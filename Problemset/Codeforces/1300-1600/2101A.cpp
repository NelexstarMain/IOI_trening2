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
    int n; std::cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    int x = n / 2, y = n / 2;  
    if (n % 2 == 0) x--, y--;   

    int val = 0;                
    mat[x][y] = val++;

    int step = 1;                

    while (val < n * n) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int dir = 0; dir < 4; dir++) {
            for (int s = 0; s < step; s++) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < n && y >= 0 && y < n)
                    mat[x][y] = val++;
            }
            if (dir == 1 || dir == 3) step++;
        }
    }
    for (auto &row : mat) {
        for (auto &v : row) cout << v << " ";
        cout << "\n";
    }
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