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
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {   
        for (int j = 0; j < m; j++) {
            int c; std::cin >> c;
            if (i == 0 && j > 0) {
                a[i][j] = a[i][j-1] + c;
            } else if (i > 0) {
                if (j == 0) {
                    a[i][j] = a[i-1][j] + c;
                } else {
                    a[i][j] = std::max(a[i][j-1], a[i-1][j]) + c;
                }
            } else {
                a[i][j] = c;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i][m-1] << " ";
        // for (int x: a[i]) std::cout << x << " ";
        // std::cout << "\n";
    } std::cout << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
