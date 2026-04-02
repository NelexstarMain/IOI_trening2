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
    int A, B, C; cin >> A >> B >> C;
    for (int x=-100; x<100; x++) {
        for (int y=-100; y<100; y++) {
            for (int z=-100; z<100; z++) {
                if (x==y || y==z || x==z) continue;
                if ((x+y+z)==A && (x*y*z)==B && (x*x+y*y+z*z)==C) {cout << x << " " << y << " " <<  z << "\n"; return ; }
            }
        }
    }
    cout << "No solution.\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
