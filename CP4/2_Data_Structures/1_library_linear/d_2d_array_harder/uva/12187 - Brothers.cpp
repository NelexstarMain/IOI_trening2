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
    int n, r, c, k; 
    while (std::cin >> n >> r >> c >> k && n > 0) {
        std::vector<std::vector<int>> a(r, std::vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int curr; std::cin >> curr;
                a[i][j] = curr;
            }
        }
        for (int b = 0; b < k; b++) {
            std::vector<std::vector<int>> templ = a;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int nx[] = {-1, 1, 0, 0};
                    int ny[] = {0, 0, -1, 1};
                    for (int z = 0; z < 4; z++) {
                        int nex = nx[z]+j;
                        int ney = ny[z]+i;
                        if (0 <= nex && 0 <= ney && nex < c && ney < r && (templ[ney][nex] == templ[i][j]+1 || (templ[ney][nex] == 0 && templ[i][j] == n-1))) {
                            a[ney][nex] = templ[i][j];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << a[i][j] << ((j == c-1) ? "": " ");
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
