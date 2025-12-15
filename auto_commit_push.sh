#!/bin/bash
set -e 

RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START ---"
git add -A
if [ -z "$(git status --porcelain)" ]; then
    echo "⚠️ Brak zmian do zatwierdzenia. Kończę."
    exit 0
fi
echo "$RANDOM_STRING"
git commit -m "$RANDOM_STRING"
echo "(Pull)..."
git pull --rebase --autostash
echo "(Push)..."
git push -u origin HEAD

echo "--- READY ---"