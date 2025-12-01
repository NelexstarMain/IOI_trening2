#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    int diff = n - m;
    l = abs(l);
    if (l >= diff) {
        l -= diff;
        diff = 0;
    }
    else {
        diff -= l;
        l = 0;
    }
    cout << -l << " " << r - diff << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}