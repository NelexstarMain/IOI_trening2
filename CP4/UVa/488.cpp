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

bool used = false;

void solve() {
    int a, f; std::cin >> a >> f;
    for (int i = 0; i < f; i++) {
        if (used) std::cout << "\n";
        used = true;
        for (int j = 1; j <= a; j++) {
            for (int z = 0; z < j; z++) cout << j;
            cout << "\n";
        }
        for (int j = a - 1; j >= 1; j--) {
            for (int z = 0; z < j; z++) cout << j;
            cout << "\n";
        }
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
