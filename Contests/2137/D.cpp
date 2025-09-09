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
    std::vector<int> a(n, 0), res(n); for (int& x: a) std::cin >> x;
    std::vector<pii> pairs; 
    for (int i = 0; i < n; i++) {
        pairs.push_back({a[i], i});
    }
    std::sort(ALL(pairs));
    int limit = 0, num = 1, current = -INF;
    for (int i = 0; i < n; i++) {
        int now = pairs[i].first, indx = pairs[i].second;
        if (now == current) {
            limit--;
        } else {
            if (limit != 0) {
                std::cout << -1 << "\n"; return;
            } else {
                limit = now-1;
                current = now;
                num++;
            }
        }
        res[indx] = num;
    }
    for (int x: res) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    fast_io();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}