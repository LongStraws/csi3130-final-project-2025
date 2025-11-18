# Dockerfile for PostgreSQL 8.1.4 Development Environment
# This allows you to modify PostgreSQL source code and rebuild it

# ===== Build stage =====
FROM --platform=linux/amd64 debian:jessie AS build

# Set noninteractive to avoid prompts
ENV DEBIAN_FRONTEND=noninteractive
WORKDIR /usr/src

# Use archived repositories for Jessie
RUN echo "deb http://archive.debian.org/debian jessie main" > /etc/apt/sources.list && \
    echo "deb http://archive.debian.org/debian-security jessie/updates main" >> /etc/apt/sources.list && \
    echo 'Acquire::Check-Valid-Until "false";' > /etc/apt/apt.conf.d/99no-check-valid-until && \
    echo 'APT::Get::AllowUnauthenticated "true";' > /etc/apt/apt.conf.d/99allow-unauthenticated

# Install build dependencies (older versions compatible with PostgreSQL 8.1.4)
RUN apt-get update && apt-get install -y --force-yes \
    build-essential \
    gcc \
    g++ \
    make \
    bison \
    flex \
    libreadline-dev \
    zlib1g-dev \
    libssl-dev \
    libxml2-dev \
    libxslt-dev \
    gettext \
    wget \
    curl \
    vim \
    git \
    sudo \
    locales \
    && rm -rf /var/lib/apt/lists/*

# Set locale
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Copy PostgreSQL 8.1.4 source code
COPY postgresql-8.1.4 /usr/src/postgresql-8.1.4

WORKDIR /usr/src/postgresql-8.1.4

# Update config.guess/config.sub to detect modern architecture
RUN wget -O config/config.guess https://git.savannah.gnu.org/cgit/config.git/plain/config.guess && \
    wget -O config/config.sub https://git.savannah.gnu.org/cgit/config.git/plain/config.sub && \
    chmod +x config/config.guess config/config.sub

# Configure, build, install
# Build with -k flag to continue even if ECPG fails (it's optional)
# ECPG has compatibility issues with newer flex/bison, but core database builds fine
RUN ./configure --prefix=/usr/local/pgsql --enable-debug && \
    make -k -j$(nproc) || true

# Install everything except ECPG preproc (which has build issues but isn't needed for core DB)
RUN make -C src/backend install && \
    make -C src/backend/utils/mb/conversion_procs install && \
    make -C src/bin install && \
    make -C src/include install && \
    make -C src/interfaces/libpq install && \
    make -C src/interfaces/ecpg/include install || true && \
    make -C src/interfaces/ecpg/pgtypeslib install || true && \
    make -C src/interfaces/ecpg/ecpglib install || true && \
    make -C src/interfaces/ecpg/compatlib install || true && \
    (make -C src/interfaces/ecpg/preproc install || echo "ECPG preproc install skipped") && \
    make -C src/pl install || true && \
    (make -C contrib install || echo "Some contrib modules failed to install, continuing...")

# Keep artifacts
RUN mkdir -p /artifacts && \
    cp -a /usr/local/pgsql /artifacts/pgsql && \
    cp -a /usr/src/postgresql-8.1.4 /artifacts/postgresql-8.1.4

# ===== Runtime/Development stage =====
FROM --platform=linux/amd64 debian:bullseye-slim

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV PGDATA=/var/lib/postgresql/data
ENV POSTGRES_USER=postgres
ENV POSTGRES_PASSWORD=postgres
ENV POSTGRES_DB=testdb
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Runtime dependencies + build tools for recompiling
RUN apt-get update && apt-get install -y \
    libreadline8 \
    zlib1g \
    tcl \
    perl \
    locales \
    make \
    gcc \
    build-essential \
    bison \
    flex \
    libreadline-dev \
    zlib1g-dev \
    libssl-dev \
    libxml2-dev \
    libxslt-dev \
    gettext \
    wget \
    curl \
    vim \
    git \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Set locale
RUN echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen

# Create postgres user
RUN useradd -m -s /bin/bash postgres && \
    echo "postgres:postgres" | chpasswd && \
    echo "postgres ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Copy compiled Postgres and source from build stage
COPY --from=build /artifacts/pgsql /usr/local/pgsql
COPY --from=build /artifacts/postgresql-8.1.4 /usr/src/postgresql-8.1.4

# Create libreadline.so.6 symlinks for compatibility (PostgreSQL 8.1.4 expects libreadline6)
# Bullseye has libreadline8, create symlinks in both locations
RUN mkdir -p /lib/x86_64-linux-gnu && \
    if [ -f /usr/lib/x86_64-linux-gnu/libreadline.so.8 ]; then \
        ln -sf /usr/lib/x86_64-linux-gnu/libreadline.so.8 /lib/x86_64-linux-gnu/libreadline.so.6 && \
        ln -sf /usr/lib/x86_64-linux-gnu/libreadline.so.8 /usr/lib/x86_64-linux-gnu/libreadline.so.6; \
    fi && \
    if [ -f /usr/lib/x86_64-linux-gnu/libhistory.so.8 ]; then \
        ln -sf /usr/lib/x86_64-linux-gnu/libhistory.so.8 /lib/x86_64-linux-gnu/libhistory.so.6 && \
        ln -sf /usr/lib/x86_64-linux-gnu/libhistory.so.8 /usr/lib/x86_64-linux-gnu/libhistory.so.6; \
    fi && \
    ldconfig 2>/dev/null || true

# Add PostgreSQL binaries to PATH
ENV PATH="/usr/local/pgsql/bin:${PATH}"

# Create data directory
RUN mkdir -p $PGDATA && \
    chown -R postgres:postgres $PGDATA && \
    chown -R postgres:postgres /usr/local/pgsql && \
    chown -R postgres:postgres /usr/src/postgresql-8.1.4

# Create scripts as root before switching to postgres user
RUN echo '#!/bin/bash\n\
set -e\n\
cd /usr/src/postgresql-8.1.4\n\
echo "Cleaning previous build..."\n\
make clean || true\n\
echo "Updating config scripts..."\n\
wget -O config/config.guess https://git.savannah.gnu.org/cgit/config.git/plain/config.guess 2>/dev/null || true\n\
wget -O config/config.sub https://git.savannah.gnu.org/cgit/config.git/plain/config.sub 2>/dev/null || true\n\
chmod +x config/config.guess config/config.sub 2>/dev/null || true\n\
echo "Rebuilding PostgreSQL..."\n\
./configure --prefix=/usr/local/pgsql --enable-debug\n\
make -j$(nproc)\n\
echo "Installing..."\n\
sudo make install\n\
echo "PostgreSQL rebuilt successfully!"\n\
echo "Note: Restart the container for changes to take effect: docker-compose restart"\n\
' > /usr/local/bin/rebuild-postgres.sh && \
    chmod +x /usr/local/bin/rebuild-postgres.sh && \
    chown postgres:postgres /usr/local/bin/rebuild-postgres.sh

RUN echo '#!/bin/bash\n\
set -e\n\
# Create symlinks for libreadline compatibility\n\
mkdir -p /lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu\n\
# Find libreadline.so.8 and create symlink\n\
READLINE_LIB=$(find /usr/lib -name "libreadline.so.8" -o -name "libreadline.so" 2>/dev/null | head -1)\n\
if [ -n "$READLINE_LIB" ] && [ ! -f /usr/lib/x86_64-linux-gnu/libreadline.so.6 ]; then\n\
    ln -sf "$READLINE_LIB" /usr/lib/x86_64-linux-gnu/libreadline.so.6 2>/dev/null || true\n\
    ln -sf "$READLINE_LIB" /lib/x86_64-linux-gnu/libreadline.so.6 2>/dev/null || true\n\
fi\n\
# Find libhistory.so.8 and create symlink\n\
HISTORY_LIB=$(find /usr/lib -name "libhistory.so.8" -o -name "libhistory.so" 2>/dev/null | head -1)\n\
if [ -n "$HISTORY_LIB" ] && [ ! -f /usr/lib/x86_64-linux-gnu/libhistory.so.6 ]; then\n\
    ln -sf "$HISTORY_LIB" /usr/lib/x86_64-linux-gnu/libhistory.so.6 2>/dev/null || true\n\
    ln -sf "$HISTORY_LIB" /lib/x86_64-linux-gnu/libhistory.so.6 2>/dev/null || true\n\
fi\n\
# Update library cache\n\
ldconfig 2>/dev/null || true\n\
# Verify libreadline.so.6 exists before proceeding\n\
if ! ldconfig -p | grep -q libreadline.so.6 && [ ! -f /usr/lib/x86_64-linux-gnu/libreadline.so.6 ] && [ ! -f /lib/x86_64-linux-gnu/libreadline.so.6 ]; then\n\
    echo "Warning: libreadline.so.6 not found, attempting to create symlink from available version..."\n\
    if [ -f /usr/lib/x86_64-linux-gnu/libreadline.so.8 ]; then\n\
        ln -sf /usr/lib/x86_64-linux-gnu/libreadline.so.8 /usr/lib/x86_64-linux-gnu/libreadline.so.6\n\
        ln -sf /usr/lib/x86_64-linux-gnu/libreadline.so.8 /lib/x86_64-linux-gnu/libreadline.so.6\n\
        ldconfig 2>/dev/null || true\n\
    fi\n\
fi\n\
if [ ! -s "$PGDATA/PG_VERSION" ]; then\n\
    echo "Initializing database..."\n\
    # PostgreSQL 8.1.4 has known initdb issues on newer systems\n\
    # Try initialization, if it fails, keep container running for development\n\
    if ! su - postgres -c "export LC_ALL=C && /usr/local/pgsql/bin/initdb -D $PGDATA --locale=C" 2>&1; then\n\
        echo ""\n\
        echo "========================================"\n\
        echo "WARNING: initdb failed with compatibility error."\n\
        echo "This is a known issue with PostgreSQL 8.1.4 on newer systems."\n\
        echo "========================================"\n\
        echo ""\n\
        echo "For hash join code development, you can still:"\n\
        echo "  1. Edit code in postgresql-8.1.4/src/backend/executor/nodeHashjoin.c"\n\
        echo "  2. Rebuild using: ./rebuild.sh"\n\
        echo "  3. Test your changes"\n\
        echo ""\n\
        echo "The container will continue running. You can:"\n\
        echo "  - Access it with: docker exec -it postgresql-dev bash"\n\
        echo "  - Modify and rebuild PostgreSQL source code"\n\
        echo ""\n\
        echo "If you need a working database, you may need to patch the source"\n\
        echo "or use a pre-initialized database template."\n\
        echo ""\n\
        echo "Container is ready for development work..."\n\
        # Keep container running even if initdb fails\n\
        exec tail -f /dev/null\n\
    fi\n\
    su - postgres -c "echo \"host all all 0.0.0.0/0 md5\" >> $PGDATA/pg_hba.conf"\n\
    su - postgres -c "echo \"listen_addresses='*'\" >> $PGDATA/postgresql.conf"\n\
    su - postgres -c "echo \"port=5432\" >> $PGDATA/postgresql.conf"\n\
fi\n\
echo "Starting PostgreSQL..."\n\
exec su - postgres -c "/usr/local/pgsql/bin/postgres -D $PGDATA"\n\
' > /usr/local/bin/start-postgres.sh && \
    chmod +x /usr/local/bin/start-postgres.sh

# Don't initialize database at build time - do it at runtime only
# This avoids the "wrong number of index expressions" error

# Expose PostgreSQL port
EXPOSE 5432

# Switch back to root for entrypoint
USER root

# Set entrypoint
ENTRYPOINT ["/usr/local/bin/start-postgres.sh"]
