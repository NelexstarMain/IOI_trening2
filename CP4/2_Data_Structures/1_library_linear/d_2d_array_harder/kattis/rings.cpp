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
// 6 6
// .TT...
// TTTT..
// TTTTT.
// TTTTT.
// TTTTTT
// ..T...

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        std::string c; std::cin >> c;
        for (int j = 0; j < m; j++) {
            if (c[j] == '.') {
                a[i].PB(0);
            } else if (c[j] == 'T') {
                a[i].PB(-1);
            }
        }    
    }
    int num = 1;
    int nx[] = {-1, 1, 0, 0};
    int ny[] = {0, 0, -1, 1};
    while (true) {
        int count = 0;
        std::vector<std::vector<int>> newv = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != -1) continue; 

                bool eadge = (i == 0 || i == n-1 || j == 0 || j == m-1);
                bool neigh = false;

                int nx[] = {-1, 1, 0, 0};
                int ny[] = {0, 0, -1, 1};

                for (int d = 0; d < 4; d++) {
                    int ney = i + ny[d];
                    int nex = j + nx[d];

                    if (ney >= 0 && ney < n && nex >= 0 && nex < m) {
                        if (a[ney][nex] != -1 && a[ney][nex] == num-1) {
                            neigh = true;
                            break;
                        }
                    }
                }

                if (eadge || neigh) {
                    newv[i][j] = num;
                    count++;
                }
            }
        }
        a = newv;
        num++;
        if (count == 0) break;
    }
    for (int i = 0; i < n; i++) {
        std::string curr = "";
        for (int j = 0; j < m; j++) {
            std::string now = ((num < 10) ? "" : ".");
            if (a[i][j] == 0) {
                now = now + "..";
            } else {
                if (a[i][j] < 10) {
                    now = now + "." + std::to_string(a[i][j]);
                } else {
                    now = now + std::to_string(a[i][j]);
                }
            }
            curr = curr + now;
        }
        std::cout << curr << "\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
