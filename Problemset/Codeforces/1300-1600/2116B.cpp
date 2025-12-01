// #include <iostream>
// #include <vector>
// #include <climits>

// const long long mod = 998244353;

// void solve() {
//     int n; std::cin >> n;
//     std::vector<int> p(n), q(n), res(n);
//     for (int& x : p) std::cin >> x;
//     for (int& x : q) std::cin >> x;

//     for (int i = 0; i < n; ++i) {
//         long long max_val = 0;
//         for (int j = 0; j <= i; ++j) {
//             long long a = 1LL << p[j];
//             long long b = 1LL << q[i - j];
//             max_val = std::max(max_val, a + b);
//         }
//         res[i] = max_val % mod;
//     }

//     for (auto& x : res) std::cout << x << " ";
//     std::cout << "\n";
// }



// int main() {
//     int T; std::cin >> T;
//     while (T--) solve();
//     return 0;
// }


#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

const int Mod = 998244353;
const int N_MAX = 1e5 + 5;
long long s[N_MAX] = {};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), q(n);
    for (int& x : p) std::cin >> x;
    for (int& x : q) std::cin >> x;

    int i = 0, j = 0;
    for (int k = 0; k < n; k++) {
        // Znajdujemy indeksy maksimów w prefiksach tablic p i q
        if (p[i] < p[k]) i = k;
        if (q[j] < q[k]) j = k;

        // Warunki z oryginalnego rozwiązania
        if (p[i] > q[j]) {
            std::cout << (s[p[i]] + s[q[k - i]]) % Mod << " ";
        } else if (q[j] > p[i]) {
            std::cout << (s[q[j]] + s[p[k - j]]) % Mod << " ";
        } else { // p[i] == q[j]
            std::cout << (s[p[i]] + s[std::max(p[k - j], q[k - i])]) % Mod << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    s[0] = 1;
    for (int i = 1; i < N_MAX; i++) {
        s[i] = (s[i - 1] * 2) % Mod;
    }

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}