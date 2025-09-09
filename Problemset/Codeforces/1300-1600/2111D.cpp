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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> classes(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> classes[i];
    }
    std::sort(classes.begin(), classes.end());

    std::vector<std::vector<int>> groups(n);
    int class_idx = 0;
    
    while (class_idx < m) {
        for (int i = 0; i < n && class_idx < m; ++i) {
            groups[i].push_back(classes[class_idx++]);
        }
        for (int i = n - 1; i >= 0 && class_idx < m; --i) {
            groups[i].push_back(classes[class_idx++]);
        }
    }

    for (const auto& group : groups) {
        for (int val : group) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
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