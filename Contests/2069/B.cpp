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
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    map<int,int> color_steps; 
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int color = grid[i][j];
            bool has_neighbor = false;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==color) {
                    has_neighbor = true;
                    break;
                }
            }
            if (has_neighbor) color_steps[color] = 2;
            else if (color_steps.find(color) == color_steps.end()) color_steps[color] = 1;
        }
    }

    int sum = 0;
    int maxi = 0;
    for (auto &[col, steps] : color_steps) {
        sum += steps;
        maxi = max(maxi, steps);
    }

    cout << sum - maxi << "\n";
}


int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}