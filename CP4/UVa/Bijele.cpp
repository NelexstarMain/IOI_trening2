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
    int a, b, c, d, e, f; std::cin >> a >> b >> c >> d >> e >> f;
    int as = 1, bs = 1, cs = 2, ds = 2, es = 2, fs = 8;
    std::cout << as-a << " " << bs-b << " " << cs-c << " " << ds-d << " " << es-e << " " << fs-f;
     
}

int main() {
    fast_io();
    solve();
    return 0;
}
