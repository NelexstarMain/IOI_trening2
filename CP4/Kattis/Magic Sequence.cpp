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

// 3
// 7
// 7 7 12
// 1 20
// 7
// 16 1 15
// 1 14
// 7
// 2 5 6
// 1 19

std::vector<int> vec(10e6+5, 0);
std::vector<int> vec2;

void solve() {
    int n; std::cin >> n;
    ll a, b, c; std::cin >> a >> b >> c;
    ll x, y; std::cin >> x >> y;
    if (c < 10e6) {
        fill(vec.begin(), vec.end(), 0);
        ll sb = a;
        for (int i = 0; i < n; i++) {
            vec[sb]++;
            sb = (sb*b+a)%c;
        }
        ll V = 0;
        for (int i = 0; i < 10e6+5; i++) {
            if (vec[i] == 0) continue;
            for (int j = 0; j < vec[i]; j++) {
                V = (V*x+i)%y;
            }
        }
        std::cout << V << "\n";
    } else {
        vec2.clear();
        ll sb = a;
        for (int i = 0; i < n; i++) {
            vec2.PB(sb);
            sb = (sb*b+a)%c;
        }
        std::sort(ALL(vec2));
        ll V = 0;
        for (int z: vec2) {
            V = (V*x+z)%y;
        }
        std::cout << V << "\n";
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
