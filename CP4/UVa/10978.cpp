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
        std::vector<std::string> r(n, "*");
        int j = -1;
        for (int i = 0; i < n; i++) {
            std::string c, w; std::cin >> c >> w;
            int z = 0;
            while (z < SIZE(w)) {
                j = (j+1)%n;
                if (r[j] == "*") z++;
            }
            r[j] = c;
        }
        for (int i = 0; i < n; i++) std::cout << r[i] << (i == n - 1 ? "" : " ");
        std::cout << "\n";
    }
    
}

int main() {
    fast_io();
    int t = 1;
    solve();
    return 0;
}
