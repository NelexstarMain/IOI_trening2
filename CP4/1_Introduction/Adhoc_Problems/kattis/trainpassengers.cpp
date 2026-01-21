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
    int m, n; std::cin >> m >> n;
    int count_in_train = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c; std::cin >> a >> b >> c;
        if (count_in_train-a < 0) {
            std::cout << "impossible\n"; 
            return;
        }
        count_in_train -= a;
        count_in_train += b;
        if (count_in_train > m) {
            std::cout << "impossible\n"; 
            return;
        }
        if (count_in_train < m && c > 0) {
            std::cout << "impossible\n";
            return;
        }
    } 
    if (count_in_train != 0) {
        std::cout << "impossible\n";
    } else {
        std::cout << "possible\n";
    }
    return;
}

int main() {
    fast_io();
    solve();
    return 0;
}
