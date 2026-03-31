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
    std::map<char, std::pair<int, int>> a;


    int n, t, m; std::cin >> n >> t >> m;
    std::set<char> e;
    for (int i = 0; i < n; i++) e.insert(char('A' + i));
    std::map<int, std::set<char>> u;
    for (int i = 0; i < m; i++) {
        int time, team; std::cin >> time >> team;
        char exer; std::cin >> exer;
        std::string acce; std::cin >> acce;
        if (acce == "Yes" && u[team].find(exer) == u[team].end()) {
            a[exer] = {time, team};
            u[team].insert(exer);
        }
    }
    for (auto x: e) {
        if (a.find(x) != a.end()) std::cout << x << " " << a[x].first << " " << a[x].second << "\n";
        else std::cout << x << " - -\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
