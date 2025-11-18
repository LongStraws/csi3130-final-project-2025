#!/bin/bash
# Script to set up test data for hash join testing
# Usage: ./setup-test-data.sh

set -e

echo "Setting up test data in PostgreSQL..."

# Check if container is running
if ! docker ps | grep -q postgresql-dev; then
    echo "Error: postgresql-dev container is not running."
    echo "Please start it first with: docker-compose up -d"
    exit 1
fi

# Wait for PostgreSQL to be ready
echo "Waiting for PostgreSQL to be ready..."
sleep 2

# Create test tables and insert data
docker exec -i postgresql-dev psql -U postgres -d testdb <<EOF
-- Drop tables if they exist
DROP TABLE IF EXISTS employees CASCADE;
DROP TABLE IF EXISTS departments CASCADE;

-- Create test tables
CREATE TABLE employees (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    department_id INTEGER,
    salary INTEGER
);

CREATE TABLE departments (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    location VARCHAR(100)
);

-- Insert test data
INSERT INTO departments (name, location) VALUES 
    ('Engineering', 'Building A'),
    ('Sales', 'Building B'),
    ('Marketing', 'Building C'),
    ('HR', 'Building A'),
    ('Finance', 'Building B');

-- Insert more employees to make hash join more likely
INSERT INTO employees (name, department_id, salary) VALUES
    ('Alice', 1, 75000),
    ('Bob', 1, 80000),
    ('Charlie', 2, 60000),
    ('Diana', 3, 65000),
    ('Eve', 1, 70000),
    ('Frank', 2, 55000),
    ('Grace', 3, 60000),
    ('Henry', 4, 50000),
    ('Ivy', 5, 55000),
    ('Jack', 1, 90000),
    ('Karen', 2, 65000),
    ('Liam', 3, 70000),
    ('Mia', 4, 52000),
    ('Noah', 5, 58000);

-- Create indexes
CREATE INDEX idx_employees_dept ON employees(department_id);

-- Show table sizes
SELECT 'employees' as table_name, COUNT(*) as row_count FROM employees
UNION ALL
SELECT 'departments', COUNT(*) FROM departments;

-- Show a sample query plan (this should use hash join)
EXPLAIN ANALYZE
SELECT e.name, e.salary, d.name as dept_name, d.location
FROM employees e 
JOIN departments d ON e.department_id = d.id
WHERE e.salary > 60000;

EOF

echo ""
echo "Test data setup complete!"
echo "You can now test your hash join modifications."
echo ""
echo "To connect to the database:"
echo "  docker exec -it postgresql-dev psql -U postgres -d testdb"

