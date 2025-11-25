#include <bits/stdc++.h>

using namespace std;
;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    char a;
    int n, m; std::cin >> a;
    std::cin >> n >> m;
    if (a == 'r') {
        std::cout << std::min(n,m) << "\n";
    } else if (a == 'Q') {
        std::cout << ((n==m)? n-1 : std::min(n,m)) << "\n";
    } else if (a == 'K') {
        std::cout << ((std::floor((n-1)/2)+1) * (std::floor((m-1)/2)+1)) << "\n";
    } else if (a == 'k') {
        std::cout << (n * m + 1) / 2 << "\n";
    }
}

int main() {
    fast_io();
    int t; std::cin >> t;
    while (t--) solve();
    // solve();
    return 0;
}
