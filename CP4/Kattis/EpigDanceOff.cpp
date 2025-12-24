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
    int x, y; std::cin >> x >> y;
    std::vector<std::string> m;
    for (int i = 0; i < x; i++) {
        std::string c; std::cin >> c;
        m.PB(c);
    }
    int co = 0;
    for (int i = 0; i < y; i++) {
        bool v = true;
        for (int j = 0; j < x; j++) {
            if (m[j][i] == '_' && v) v=true;
            else v=false;
        }
        if (v) co++;
    }
    co++;
    std::cout << co << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
