#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n;
    while (cin >> n && n != -1) {
        vector<vector<int>> adj(n, std::vector<int>(n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int curr; cin >> curr;
                adj[i][j] = curr;
            }
        }
        vector<int> res;
        for (int i=0; i<n; i++) {
            vector<int> used;
            for (int j=0; j<n; j++) if (adj[i][j]) used.PB(j);
            bool triangle = false;
            for (int a = 0; a < SIZE(used); a++) {
                for (int b = a+1; b < SIZE(used); b++) {
                    if (a == b) continue;
                    int u = used[a], v = used[b];
                    if (adj[u][v] == 1) triangle = true;
                }
            }
            if (!triangle) res.PB(i);
        }
        if (SIZE(res) > 0) for (int x: res) cout << x << " ";
        else cout << "\n";
        cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
