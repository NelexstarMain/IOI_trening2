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
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (n == 2) {
        std::cout << 0 << "\n";
        return;
    }
    int ans = 0, mx = 0, cnt;
    for (int i = 0; i < n; i++) {
        if (a[i].size() == 1) {
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j: a[i]) {
            cnt += (a[j].size() == 1);
        }
        mx = std::max(mx, cnt);
    }
    std::cout << ans - mx << "\n";
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