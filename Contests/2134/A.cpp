#include <iostream>

void solve() {
    long long n, a, b;
    std::cin >> n >> a >> b;

    if ((n - b) % 2 != 0) {
        std::cout << "NO\n";
        return;
    }

    if (a <= b) {
        std::cout << "YES\n";
    } else {
        if ((n - a) % 2 == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
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