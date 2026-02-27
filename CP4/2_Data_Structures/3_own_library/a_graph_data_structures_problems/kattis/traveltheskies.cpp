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

// 2 2 2
// 1 2 1 30
// 2 1 2 50
// 2 1 10
// 1 1 30
// 1 2 10
// 2 2 10

struct flight {
    int s, e, c;
};

void solve() {
    int k, n, m; std::cin >> k >> n >> m;
    std::vector<std::vector<flight>> flights(10);
    std::vector<std::vector<int>> passengers(10, std::vector<int>(15, 0));

    for (int i = 0; i < m; i++) {
        int v, u, d, z; std::cin >> v >> u >> d >> z;
        flights[d].PB({v, u, z});
    }
    int a, b, c;
    for (int i = 0; i < n*k; i++) {
        std::cin >> a >> b >> c;
        passengers[b][a] += c;
    }
    bool valid = true;
    std::vector<int> peronscapacity(15, 0);
    for (int day = 1; day <= n; day++) {
        for (int i = 0; i < 15; i++) {
            peronscapacity[i] += passengers[day][i];
        }
        for (auto f: flights[day]) {
            if (peronscapacity[f.s] >= f.c) {
                peronscapacity[f.s] -= f.c;
                passengers[day+1][f.e] += f.c;
            } else {
                valid = false;
                break;
            }
        }
    }
    std::cout << ((valid)?"":"sub") << "optimal\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}

