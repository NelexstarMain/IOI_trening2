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
    int n; 
    while (std::cin >> n && n != 0) {
        std::vector<int> start_grid(n, 0);
        bool possible = true;

        for (int i = 0; i < n; i++) {
            int C, P; 
            std::cin >> C >> P; 
            int start_pos = i + P;
            if (!possible || start_pos < 0 || start_pos >= n || start_grid[start_pos] != 0) {
                possible = false;
            } else {
                start_grid[start_pos] = C;
            }
        }

        if (!possible) {
            std::cout << "-1" << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                std::cout << start_grid[i] << (i == n - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    } 
}

int main() {
    fast_io();
    solve();
    return 0;
}
