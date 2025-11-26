# PostgreSQL 8.1.4 Development Environment

This Docker setup allows you to modify PostgreSQL 8.1.4 source code (especially hash join code) and rebuild it in a containerized environment.

## Quick Start

1. **Build and start the container:**

   ```bash
   docker-compose up -d
   ```

2. **Wait for PostgreSQL to start** (check logs):

   ```bash
   docker-compose logs -f
   ```

3. **Connect to the database:**
   ```bash
   docker exec -it postgresql-dev psql -U postgres -d testdb
   ```

## Making Code Changes

The PostgreSQL source code is mounted as a volume, so you can edit files directly on your host machine.

### Hash Join Files

The main hash join implementation files are:

- `postgresql-8.1.4/src/backend/executor/nodeHashjoin.c`
- `postgresql-8.1.4/src/include/executor/nodeHashjoin.h`
- `postgresql-8.1.4/src/include/executor/hashjoin.h`

### Rebuilding After Changes

After modifying the C code, rebuild PostgreSQL:

```bash
# Rebuild only
./rebuild.sh

# Rebuild and restart container automatically
./rebuild.sh --restart
```

Or manually:

```bash
docker exec -u postgres postgresql-dev /usr/local/bin/rebuild-postgres.sh
docker-compose restart
```

## Creating Test Data

### Quick Setup (Recommended)

Use the provided script to set up test data:

```bash
./setup-test-data.sh
```

This will create sample tables (`employees` and `departments`) with test data and run a sample query that uses hash joins.

### Manual Setup

Once connected to the database, you can create tables and insert data:

```sql
-- Create test tables
CREATE TABLE employees (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    department_id INTEGER
);

CREATE TABLE departments (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100)
);

-- Insert test data
INSERT INTO departments (name) VALUES
    ('Engineering'),
    ('Sales'),
    ('Marketing');

INSERT INTO employees (name, department_id) VALUES
    ('Alice', 1),
    ('Bob', 1),
    ('Charlie', 2),
    ('Diana', 3);

-- Test hash join (force hash join with a larger dataset)
SET enable_hashjoin = on;
SET enable_mergejoin = off;
SET enable_nestloop = off;

-- This should use a hash join
EXPLAIN ANALYZE
SELECT e.name, d.name
FROM employees e
JOIN departments d ON e.department_id = d.id;
```

## Useful Commands

- **View logs:**

  ```bash
  docker-compose logs -f
  ```

- **Stop container:**

  ```bash
  docker-compose down
  ```

- **Stop and remove volumes (fresh start):**

  ```bash
  docker-compose down -v
  ```

- **Access container shell:**

  ```bash
  docker exec -it postgresql-dev bash
  ```

- **Connect from host machine:**
  ```bash
  psql -h localhost -p 5432 -U postgres -d testdb
  ```
  (Password: `postgres`)

## Notes

- The database data persists in a Docker volume named `postgres_data`
- Source code changes are immediately visible in the container (via volume mount)
- After rebuilding, PostgreSQL will automatically restart
- The container runs PostgreSQL in the foreground for easy debugging

## Troubleshooting

### Database Initialization Error (RESOLVED)

**"FATAL: wrong number of index expressions" during initdb:**

- This was a known compatibility issue with PostgreSQL 8.1.4's bootstrap code on modern systems
- The error was caused by GCC's aggressive loop optimizations affecting how PostgreSQL 8.1.4 handles index creation during bootstrap
- **Solution**: The Dockerfile now compiles PostgreSQL with `-fno-aggressive-loop-optimizations` flag, which prevents the compiler optimization that caused the issue
- The database now initializes successfully and PostgreSQL 8.1.4 is fully functional

### Build Errors

**"cannot guess build type" or "unable to guess system type":**

- This happens on ARM64 (Apple Silicon) because PostgreSQL 8.1.4's config scripts are from 2005
- The Dockerfile automatically updates the config scripts and forces x86_64 platform
- If it still fails, the docker-compose.yml is set to use `platform: linux/amd64` which forces x86_64 emulation
- On Apple Silicon, Docker Desktop will automatically use Rosetta 2 for emulation

**Other build errors:**

1. Check that all dependencies are installed
2. Make sure the source code is properly mounted
3. Check container logs: `docker-compose logs`

### PostgreSQL Won't Start

1. Check if port 5432 is already in use
2. Verify the data directory permissions
3. Check logs for specific error messages: `docker-compose logs postgres`

### Platform/Architecture Issues

If you're on Apple Silicon (M1/M2/M3) and want to build natively for ARM64:

- Comment out the `platform: linux/amd64` line in `docker-compose.yml`
- The Dockerfile will attempt to update config scripts to support ARM64
- Note: PostgreSQL 8.1.4 may not be fully tested on ARM64 architectures
