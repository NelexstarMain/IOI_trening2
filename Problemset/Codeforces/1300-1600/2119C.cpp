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
    ll n, l, r, k; std::cin >> n >> l >> r >> k;
    if (n%2==1) {
        std::cout << l << "\n";
        return;
    } else if (n == 2) {
        std::cout << -1 << "\n";
        return;
    } 
    ll res = 1;
    int found = 0;
    while (res <= r) {
        if (res > l) {
            found = 1;
            if (k < n-1) {
                std::cout << l << "\n";
            } else {
                std::cout << res << "\n";
            }
            return;
        }
        res *= 2;
    }
    if (!found) {
        std::cout << -1 << "\n";
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