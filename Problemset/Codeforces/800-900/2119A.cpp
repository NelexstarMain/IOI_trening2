
#include <iostream>
#include <algorithm>

void solve() {
    long long a, b, x, y;
    std::cin >> a >> b >> x >> y;

    if (a > b) {
        if ((a ^ 1) == b) {
            std::cout << y << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    } else {
        long long diff = b - a;
        long long cost1 = diff * x;
        long long even_count;

        if (a % 2 == 0) {
            even_count = (b - a + 1) / 2;
        } else {
            even_count = (b - a) / 2;
        }

        if (even_count > 0 && y < x) {
            long long cost2 = (diff - even_count) * x + even_count * y;
            std::cout << std::min(cost1, cost2) << std::endl;
        } else {
            std::cout << cost1 << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
