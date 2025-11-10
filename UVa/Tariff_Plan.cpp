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

void solve(int c) {
    int n; std::cin >> n;
    int mile = 0, juice = 0;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        mile += std::ceil((x+1)/30.0)*10;
        juice += std::ceil((x+1)/60.0)*15;
    }
    if (mile < juice) {
        std::cout << "Case " << c << ": Mile " << mile << '\n';
    } else if (juice < mile) {
        std::cout << "Case " << c << ": Juice " << juice << '\n';
    } else {
        std::cout << "Case " << c << ": Mile Juice " << mile << '\n';
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    int c = 0;
    while (T--) {
        solve(++c);
    }
    return 0;
}
