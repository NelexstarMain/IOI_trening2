// gen_laz.cpp
// Kompilacja: g++ -std=c++17 -O2 gen_laz.cpp -o gen_laz
// Użycie: ./gen_laz <seed>

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc < 2) {
        cerr << "Uzycie: ./gen_laz <seed>\n";
        return 1;
    }

    unsigned long long seed = stoull(argv[1]);
    if (seed < 1) seed = 1;     // <-- seed zaczyna się od 1

    mt19937_64 rng(seed);

    const int MINV = 1;
    const int MAXV = 1'000'000;

    uniform_int_distribution<int> dist(MINV, MAXV);

    int n = dist(rng);
    int m = dist(rng);

    cout << n << " " << m << "\n";
    return 0;
}
