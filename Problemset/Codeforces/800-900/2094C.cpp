#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> ans(2*n+1, 0);
    vector<bool> used(2*n+1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            ans[i + j] = x;
            used[x] = true;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i] != 0) cout << ans[i] << " ";
        else {
            for (int j = 1; j <= n * 2; j++) {
                if (!used[j]) {
                    used[j] = true;
                    cout << j << " ";
                    break;
                }
            }
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}