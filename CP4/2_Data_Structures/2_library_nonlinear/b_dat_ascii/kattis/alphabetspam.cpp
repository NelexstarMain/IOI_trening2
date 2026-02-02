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
    std::string s; std::cin >> s;
    int lc = 0, uc = 0, ws = 0, sy = 0;
    for (char x: s) {
        if (std::islower(x)) lc++;
        else if (std::isupper(x)) uc++;
        else if (x == '_') ws++;
        else sy++;
    } 
    int si = SIZE(s);
    std::cout << std::fixed << std::setprecision(16) << (double)(ws*1.0/si) << "\n" << (double)(lc*1.0/si) << "\n" << (double)(uc*1.0/si) << "\n" << (double)(sy*1.0/si) << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
