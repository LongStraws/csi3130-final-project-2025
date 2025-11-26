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

# Patch is already applied directly to the source file
# (The bootstrap-fix.patch file is kept for reference)

# Update config.guess/config.sub to detect modern architecture
RUN wget -O config/config.guess https://git.savannah.gnu.org/cgit/config.git/plain/config.guess && \
    wget -O config/config.sub https://git.savannah.gnu.org/cgit/config.git/plain/config.sub && \
    chmod +x config/config.guess config/config.sub

# Configure, build, install
# Build with -k flag to continue even if ECPG fails (it's optional)
# ECPG has compatibility issues with newer flex/bison, but core database builds fine
# Fix for "wrong number of index expressions" error: disable aggressive loop optimizations
# This is a known GCC optimization issue with PostgreSQL 8.1.4
RUN export CFLAGS='-fno-aggressive-loop-optimizations' && \
    ./configure --prefix=/usr/local/pgsql --enable-debug CFLAGS="$CFLAGS" && \
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
FROM --platform=linux/amd64 debian:jessie-slim

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV PGDATA=/var/lib/postgresql/data
ENV POSTGRES_USER=postgres
ENV POSTGRES_PASSWORD=postgres
ENV POSTGRES_DB=testdb
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Use archived repositories for Jessie
RUN echo "deb http://archive.debian.org/debian jessie main" > /etc/apt/sources.list && \
    echo "deb http://archive.debian.org/debian-security jessie/updates main" >> /etc/apt/sources.list && \
    echo 'Acquire::Check-Valid-Until "false";' > /etc/apt/apt.conf.d/99no-check-valid-until && \
    echo 'APT::Get::AllowUnauthenticated "true";' > /etc/apt/apt.conf.d/99allow-unauthenticated

# Runtime dependencies + build tools for recompiling
RUN apt-get update && apt-get install -y --force-yes \
    libreadline6 \
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

# Jessie already has libreadline6, so no symlinks needed
# But ensure library cache is updated
RUN ldconfig 2>/dev/null || true

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
# Update library cache\n\
ldconfig 2>/dev/null || true\n\
# Check if PostgreSQL binaries exist\n\
if [ ! -f "/usr/local/pgsql/bin/initdb" ]; then\n\
    echo "========================================"\n\
    echo "WARNING: PostgreSQL binaries not found!"\n\
    echo "The build may have failed. Container will keep running for debugging."\n\
    echo "You can access it with: docker exec -it postgresql-dev bash"\n\
    echo "========================================"\n\
    exec tail -f /dev/null\n\
fi\n\
if [ ! -s "$PGDATA/PG_VERSION" ]; then\n\
    echo "Initializing database..."\n\
    # Initialize database with proper locale settings\n\
    if ! su - postgres -c "export LC_ALL=C && /usr/local/pgsql/bin/initdb -D $PGDATA --locale=C" 2>&1; then\n\
        echo ""\n\
        echo "========================================"\n\
        echo "WARNING: initdb failed!"\n\
        echo "This is a known issue with PostgreSQL 8.1.4 on modern systems."\n\
        echo "========================================"\n\
        echo ""\n\
        echo "The container will continue running. You can:"\n\
        echo "  - Access it with: docker exec -it postgresql-dev bash"\n\
        echo "  - Edit code in postgresql-8.1.4/src/backend/executor/nodeHashjoin.c"\n\
        echo "  - Rebuild using: ./rebuild.sh"\n\
        echo ""\n\
        exec tail -f /dev/null\n\
    fi\n\
    # Configure PostgreSQL for network access\n\
    su - postgres -c "echo \"host all all 0.0.0.0/0 md5\" >> $PGDATA/pg_hba.conf"\n\
    # Note: We'll use command-line flags for listen_addresses and port to avoid config file syntax issues\n\
    echo "Database initialized successfully!"\n\
    echo "Note: You can create the testdb database after PostgreSQL starts using:"\n\
    echo "  docker exec -it postgresql-dev createdb -U postgres testdb"\n\
fi\n\
echo "Starting PostgreSQL..."\n\
exec su - postgres -c "/usr/local/pgsql/bin/postmaster -D $PGDATA -i"\n\
' > /usr/local/bin/start-postgres.sh && \
    chmod +x /usr/local/bin/start-postgres.sh

# Database initialization happens at runtime using Debian Jessie
# which is compatible with PostgreSQL 8.1.4's initdb process

# Expose PostgreSQL port
EXPOSE 5432

# Switch back to root for entrypoint
USER root

# Set entrypoint
ENTRYPOINT ["/usr/local/bin/start-postgres.sh"]
