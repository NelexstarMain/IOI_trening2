#include <bits/stdc++.h>

void solve() {
    std::vector<int> num(4);
    for (int& x: num) std::cin >> x;
    if (num[1] == num[0] && num[2] == num[0] && num[3] == num[0]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}