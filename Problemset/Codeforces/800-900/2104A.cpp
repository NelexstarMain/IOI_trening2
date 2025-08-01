#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if ((a + b + c) % 3 != 0) {
            std::cout << "NO\n";
            continue;
        }
        int x = (a + b + c) / 3;
        if (b <= x) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}