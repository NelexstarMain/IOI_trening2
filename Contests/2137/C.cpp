#include <iostream>

long long gcd(long long x, long long y) {
    while (y) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

int count_trailing_zeros(long long n) {
    if (n == 0) return 0;
    int count = 0;
    while (n > 0 && (n & 1) == 0) {
        n >>= 1;
        count++;
    }
    return count;
}

void solve() {
    long long a, b;
    std::cin >> a >> b;

    long long prod = a * b;

    if (prod % 2 != 0) {
        std::cout << prod + 1 << "\n";
    } else {
        if (a % 2 != 0 && b % 2 == 0) {
            if (count_trailing_zeros(b) >= 2) {
                // b is a multiple of 4
                std::cout << prod / 2 + 2 << "\n";
            } else {
                // b is a multiple of 2, but not 4
                std::cout << -1 << "\n";
            }
        } else if (a % 2 == 0 && b % 2 != 0) {
            std::cout << -1 << "\n";
        } else { // a and b are both even
            std::cout << prod / 2 + 2 << "\n";
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