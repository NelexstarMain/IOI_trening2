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
    int n, m, z; std::cin >> n >> m >> z;
    std::vector<int> a(z); for (int& x: a) std::cin >> x;
    int cnt = 1, i = 0, s = 0;
    for (int cnt = 0; cnt < n;) {
        while (s < m) {
            s += a[i];
            i++;
        }
        if (s > m) {
            std::cout << "NO\n";
            return;
        } else if (s == m) {
            cnt++;
            s = 0;
        }
        if (cnt == n) {
            std::cout << "YES\n";
            return;
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
