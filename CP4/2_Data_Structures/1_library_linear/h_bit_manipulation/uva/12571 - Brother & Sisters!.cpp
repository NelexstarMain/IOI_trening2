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
    std::vector<int> A, ANS;
    int n, q; std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int c; std::cin >> c;
        A.PB(c);
    }
    for (int i = 0; i < 230; i++) {
        int m = 0;
        for (int x: A) m = std::max(m, (i&x));
        ANS.PB(m);
    }
    for (int i = 0; i < q; i++) {
        int curr; std::cin >> curr;
        std::cout << ANS[curr] << "\n";
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
