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
    double R, B, M; std::cin >> R >> B >> M;
    int mounth = 1;
    double saldo = B;
    while (saldo > 0 && mounth <= 1200) {
        int interest = static_cast<int>(std::round(saldo * R));
        saldo += interest/100.0;
        saldo = std::round(saldo * 100) / 100;
        saldo -= M;
        if (saldo <= 0) break;
        mounth++;
    }
    if (mounth > 1200) {
        std::cout << "impossible\n";
    } else {
        std::cout << mounth << "\n";
    }
    
}

int main() {
    fast_io();  
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
