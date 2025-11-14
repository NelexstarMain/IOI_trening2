#!/usr/bin/env bash
set -euo pipefail

# Config
readonly A_CPP="a.cpp"
readonly BRUTE_CPP="brute.cpp"
readonly GEN_CPP="gen.cpp"
readonly TIMEOUT="2s"
readonly FLAGS="-std=c++17 -O2 -Wall"

# Colors
readonly C_OFF='\e[0m'
readonly C_OK='\e[32m'
readonly C_ERR='\e[31m'
readonly C_WARN='\e[33m'
readonly C_INFO='\e[36m'

cleanup() { rm -f int out1 out2; }
trap cleanup EXIT

echo -e "${C_INFO}[COMPILE] $A_CPP${C_OFF}"
g++ $FLAGS "$A_CPP" -o a.exe || exit 1

echo -e "${C_INFO}[COMPILE] $BRUTE_CPP${C_OFF}"
g++ $FLAGS "$BRUTE_CPP" -o brute.exe || exit 1

echo -e "${C_INFO}[COMPILE] $GEN_CPP${C_OFF}"
g++ $FLAGS "$GEN_CPP" -o gen.exe || exit 1

echo -e "${C_INFO}[TEST] Starting stress test...${C_OFF}\n"

for ((i=1; ; i++)); do
    echo -n "Test #$i: "

    ./gen.exe "$i" > int
    
    if ! timeout "$TIMEOUT" ./a.exe < int > out1 2>/dev/null; then
        echo -e "${C_ERR}TLE (a.exe)${C_OFF}"
        break
    fi
    
    if ! timeout "$TIMEOUT" ./brute.exe < int > out2 2>/dev/null; then
        echo -e "${C_ERR}TLE (brute.exe)${C_OFF}"
        break
    fi
    
    if diff -w out1 out2 >/dev/null 2>&1; then
        echo -e "${C_OK}OK${C_OFF}"
    else
        echo -e "${C_ERR}WA${C_OFF}"
        echo -e "\n${C_WARN}=== INPUT ===${C_OFF}"
        cat int
        echo -e "\n${C_WARN}=== OUTPUT (a.exe) ===${C_OFF}"
        cat out1
        echo -e "\n${C_WARN}=== EXPECTED (brute.exe) ===${C_OFF}"
        cat out2
        break
    fi
done
