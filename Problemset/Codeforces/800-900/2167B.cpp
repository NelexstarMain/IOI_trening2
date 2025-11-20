#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::string s, t; std::cin >> s >> t;
    std::unordered_map<char, int> cnt;
    for (char x: s) cnt[x]++;
    for (char x: t) {
        if (cnt[x] > 0) {
            cnt[x]--;
        } else {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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