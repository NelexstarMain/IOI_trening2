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
    std::vector<int> c;
    std::vector<int> mine(n), maxe(n);
    int m = -INF;
    for (int i = 0; i < n; i++) {
        int cu; std::cin >> cu;
        m = std::max(m, cu);
        mine[i] = m;
        c.PB(cu);
    }
    m = INF;
    for (int i = n-1; i >= 0; i--) {
        int cu = c[i];
        m = std::min(m, cu);
        maxe[i] = m;
    }
    int count = 0;
    if (c[n-1] == mine[n-1]) count++;
    if (c[0] == maxe[0]) count++;
    for (int i = 1; i < n-1; i++) {
        int curr = c[i];
        if (curr > mine[i-1] && curr < maxe[i+1]) count++;
    }
    std::cout << count << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
