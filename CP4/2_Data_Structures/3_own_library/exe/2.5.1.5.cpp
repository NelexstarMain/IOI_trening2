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
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> AdjentcMatrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int v, u; std::cin >> v >> u;
        AdjentcMatrix[v][u] = 1; AdjentcMatrix[u][v] = 1;
    }
    bool valid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!AdjentcMatrix[i][j]) { valid = false; break; }   
        }
    }
    if (valid) std::cout << "Complete";
    else std::cout << "not Complete";
} 

int main() {
    fast_io();
    solve();
    return 0;
}
