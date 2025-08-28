#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for (int &x : S) cin >> x;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : S) pq.push(x);

    ll score = 1;

    for (int op = 0; op < k; ++op) {
        if (pq.empty()) break;
        int m = pq.top();
        pq.pop();
        score = (score * 1LL * m) % MOD;

        for (int i = 1; i < m; ++i) {
            pq.push(i);
        }
    }

    cout << score << "\n";
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
