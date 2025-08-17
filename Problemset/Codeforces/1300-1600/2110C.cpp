#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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
    std:vector<pii> obstacles(n);
    std::vector<int> d(n); for (int& x: d) std::cin >> x;
    for (int i = 0; i < n; i++) {
        int l, r; std::cin >> l >> r;
        obstacles[i] = {l, r};
    }    
    for (int i = 0; i < n-1; i++) {
        if (obstacles[i+1].first + 1 < obstacles[i].second || obstacles[i+1].second - 1 > obstacles[i].first) {
            std::cout << "NO\n";
            return;
        }
    
    }
}

int main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}