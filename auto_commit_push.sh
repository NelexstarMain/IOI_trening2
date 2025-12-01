#!/bin/bash

# Zatrzymuje skrypt przy każdym błędzie
set -e 

RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START: Synchronizacja ---"

# 1. Dodaj WSZYSTKIE zmiany (nowe, zmienione i usunięte pliki)
git add -A

# 2. Sprawdź czy są zmiany. Jeśli git status --porcelain jest pusty, wyjdź.
if [ -z "$(git status --porcelain)" ]; then
    echo "⚠️ Brak zmian do zatwierdzenia. Kończę."
    exit 0
fi
#nowa wesjia
# 3. Commit
echo "Komitowanie: $RANDOM_STRING"
git commit -m "$RANDOM_STRING"

# 4. Pull z Rebase i Autostash (To najważniejsza linia, której brakowało)
# --autostash chroni przed brudnym katalogiem roboczym (rzadkie tu, ale bezpieczne)
echo "Pobieranie zmian (Pull)..."
git pull --rebase --autostash

# 5. Push
# -u origin HEAD: automatycznie ustawia gałąź na serwerze, jeśli jej nie ma
echo "Wysyłanie zmian (Push)..."
git push -u origin HEAD

echo "✅ GOTOWE!"