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
    int n, a, b; std::cin >> n >> a >> b;
    std::string s; std::cin >> s;
    int x = 0, y = 0;
    int maximum = 100;
    while (maximum--) {
        for (char z: s) {
            if (z == 'N') {
                y++;
            } else if (z == 'E') {
                x++;
            } else if (z == 'S') {
                y--;
            } else {
                x--;
            }
            
            if (x==a&&y==b) {
                std::cout << "YES\n";
                return;
            }
        }
        
    }
    std::cout << "NO\n";
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