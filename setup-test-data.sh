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

# Drop existing tables in dependency order (8.1 lacks IF EXISTS / multi-row inserts)
for table in manages emp dept; do
    docker exec postgresql-dev psql -U postgres -d testdb -c "DROP TABLE ${table} CASCADE" >/dev/null 2>&1 || true
done

# Create test tables and insert data
docker exec -i postgresql-dev psql -U postgres -d testdb <<'EOF'

CREATE TABLE dept (
    dno INT NOT NULL,
    dname CHAR(10),
    PRIMARY KEY (dno)
);

INSERT INTO dept VALUES (1, 'accounting');
INSERT INTO dept VALUES (2, 'sales');
INSERT INTO dept VALUES (3, 'management');
INSERT INTO dept VALUES (4, 'shipping');
INSERT INTO dept VALUES (5, 'testing');

-- Employees
CREATE TABLE emp (
    eno INT,
    ename CHAR(10),
    dno INT,
    PRIMARY KEY (eno),
    FOREIGN KEY (dno) REFERENCES dept(dno)
);

INSERT INTO emp VALUES (101,'Smith',1);
INSERT INTO emp VALUES (201,'Kevin',2);
INSERT INTO emp VALUES (105,'Sally',1);
INSERT INTO emp VALUES (102,'Matt',1);
INSERT INTO emp VALUES (402,'Jeff',4);
INSERT INTO emp VALUES (205,'Amy',2);
INSERT INTO emp VALUES (401,'Tom',4);
INSERT INTO emp VALUES (202,'Alex',2);
INSERT INTO emp VALUES (103,'Sam',1);
INSERT INTO emp VALUES (302,'Joe',3);
INSERT INTO emp VALUES (304,'Sean',3);
INSERT INTO emp VALUES (206,'Martin',2);
INSERT INTO emp VALUES (203,'Simon',2);
INSERT INTO emp VALUES (104,'Jane',1);
INSERT INTO emp VALUES (501,'Max',5);
INSERT INTO emp VALUES (303,'Mike',3);
INSERT INTO emp VALUES (106,'Sarah',1);
INSERT INTO emp VALUES (107,'Jack',1);
INSERT INTO emp VALUES (204,'Jen',2);
INSERT INTO emp VALUES (301,'John',3);

-- Managers
CREATE TABLE manages (
    eno INT,
    dno INT,
    PRIMARY KEY (eno, dno),
    FOREIGN KEY (eno) REFERENCES emp(eno),
    FOREIGN KEY (dno) REFERENCES dept(dno)
);

INSERT INTO manages VALUES (107, 1);
INSERT INTO manages VALUES (203, 2);
INSERT INTO manages VALUES (301, 3);
INSERT INTO manages VALUES (304, 5);
INSERT INTO manages VALUES (304, 4);

-- Target query for hash join testing
\pset pager off
SELECT e1.ename AS "manager", e2.ename AS "employee"
FROM emp e1, emp e2, dept d, manages m
WHERE e1.eno = m.eno
  AND m.dno = d.dno
  AND d.dno = e2.dno
ORDER BY manager;

EOF

echo ""
echo "Test data setup complete!"
echo ""
echo "To connect to the database:"
echo "  docker exec -it postgresql-dev psql -U postgres -d testdb"
