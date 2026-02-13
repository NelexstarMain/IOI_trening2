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
    std::vector<std::string> a;
    for (int i = 0; i < 5; i++) {
        std::string c; std::cin >> c;
        a.PB(c);
    }
    bool v = true;
    int co = 0;
    int xn[] = {-2, 2, -1, 1, -2, 2, -1, 1};
    int yn[] = {1, 1, 2, 2, -1, -1, -2, -2};
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (a[x][y] == 'k') {
                co++;
                for (int d = 0; d < 8; d++) {
                    int nx = x+xn[d], ny = y+yn[d];
                    if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && a[nx][ny] == 'k') v = false;
                }
            }
            
        }
    }
    if (v && co == 9) std::cout << "valid\n";
    else std::cout << "invalid\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
