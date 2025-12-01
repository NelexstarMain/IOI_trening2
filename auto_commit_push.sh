#!/bin/bash

# Użycie 'set -e' powoduje, że skrypt zatrzymuje się natychmiast, gdy 
# jakakolwiek komenda zwróci błąd (status wyjścia != 0).
set -e 

# --- Generowanie Losowego Ciągu (15 znaków) ---
RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START: Automatyczna synchronizacja ---"

# 1. Dodaj wszystkie pliki
git add .

# 2. Sprawdź, czy są zmiany do commitowania
# Jeśli nie ma zmian, kończy działanie skryptu
if git diff-index --quiet HEAD --; then
    echo "Brak zmian do zatwierdzenia. Zakończono."
    exit 0
fi

# 3. Commit zmian
git commit -m "$RANDOM_STRING"

# 4. PULL (Pobierz najnowsze zmiany z repozytorium)
# Używamy --rebase, aby umieścić nasz commit na wierzchu.
# UWAGA: Jeśli wystąpi konflikt, skrypt ZATRZYMA SIĘ!

# 5. PUSH (Wyślij nasze zmiany)
git push

echo "Zmiany zakończone pomyślnie."
echo "--- KONIEC ---"