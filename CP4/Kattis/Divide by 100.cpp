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
    std::string m, s; std::cin >> m >> s;
    int si = SIZE(s)-1;
    bool v = false;
    std::string l = "", r = "";
    for (int i = 0; i < si; i++) {
        int in = SIZE(m)-1-i;
        char cu = (in >= 0) ? m[in] : '0';
        if (cu != '0') v = true;
        if (v) l += cu;
    }
    std::reverse(ALL(l));
    if (si >= SIZE(m)) r = "0";
    else {
        int k = SIZE(m)-si;
        r = m.substr(0, k);
    }
    std::cout << r << ((l != "") ? ".":"") << l << "\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}
