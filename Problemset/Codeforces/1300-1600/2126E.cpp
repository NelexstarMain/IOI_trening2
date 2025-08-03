
#include <iostream>
#include <vector>
#include <numeric>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> p(n);
    std::vector<long long> s(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    for (int i = 0; i < n; ++i) std::cin >> s[i];

    if (n == 1) {
        std::cout << (p[0] == s[0] ? "YES\n" : "NO\n");
        return;
    }

    if (p[n - 1] != s[0]) {
        std::cout << "NO\n";
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (gcd(p[i], s[i + 1]) != p[i + 1]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
