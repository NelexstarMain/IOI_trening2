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
// 3 3
// oTs
// nwi
// eox
// 3 4
// xAxa
// yByb
// zCyc
// 0 0

void solve() {
    int n, m;
    while (std::cin >> n >> m && n > 0) {
        std::vector<std::string> col(m, "");
        for (int i = 0; i < n; i++) {   
            std::string c; std::cin >> c;
            for (int j = 0; j<m; j++) {
                col[j] += c[j];
            }
        }
        std::sort(ALL(col), [](std::string& a, std::string& b){
            std::string na = "", nb = "";
            for (char c : a) na += std::tolower(c);
            for (char c : b) nb += std::tolower(c);
            return na < nb;
        });
        for (int i = 0; i < n; i++) {
            std::string c = "";
            for (int j = 0; j<m; j++) {
                c = c + col[j][i];
            }
            std::cout << c << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
