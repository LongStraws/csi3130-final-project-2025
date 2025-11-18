#!/bin/bash
# Script to rebuild PostgreSQL after making code changes
# Usage: ./rebuild.sh [--restart]

set -e

RESTART=false
if [ "$1" == "--restart" ]; then
    RESTART=true
fi

echo "Rebuilding PostgreSQL in Docker container..."

# Check if container is running
if ! docker ps | grep -q postgresql-dev; then
    echo "Error: postgresql-dev container is not running."
    echo "Please start it first with: docker-compose up -d"
    exit 1
fi

# Rebuild PostgreSQL inside the container
docker exec -u postgres postgresql-dev /usr/local/bin/rebuild-postgres.sh

if [ "$RESTART" = true ]; then
    echo ""
    echo "Restarting container to apply changes..."
    docker-compose restart
    echo "Waiting for PostgreSQL to start..."
    sleep 3
fi

echo ""
echo "PostgreSQL has been rebuilt!"
if [ "$RESTART" = false ]; then
    echo "Note: Restart the container with 'docker-compose restart' to apply changes."
fi
echo "You can now test your changes by connecting to the database."

