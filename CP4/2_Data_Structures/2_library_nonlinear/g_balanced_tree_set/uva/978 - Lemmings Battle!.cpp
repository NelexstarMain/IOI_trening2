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
    int ba, gr, bl; std::cin >> ba >> gr >> bl;
    std::multiset<int> G, B;
    for (int i = 0; i < gr; i++) { int c; std::cin >> c; G.insert(c); }
    for (int i = 0; i < bl; i++) { int c; std::cin >> c; B.insert(c); }
    std::vector<int> Gv, Bv;
    while (SIZE(G) > 0 && SIZE(B) > 0) {
        int count = std::min(ba, std::min(SIZE(G), SIZE(B)));
        for (int i = 0; i < count; i++) {
            int left = *G.rbegin(), right = *B.rbegin();
            G.erase(prev(G.end())); B.erase(prev(B.end()));
            if (left < right) Bv.PB(right-left);
            else if (left > right) Gv.PB(left-right);
        }
        for (int x: Gv) G.insert(x);    
        for (int x: Bv) B.insert(x); 
        Gv.clear(); Bv.clear();
    }
    if (SIZE(G) > 0) {
        std::cout << "green wins\n";
        for (auto it = G.rbegin(); it != G.rend(); it++) {
            std::cout << *it << "\n";
        }
    } else if (SIZE(B) > 0) {
        std::cout << "blue wins\n";
        for (auto it = B.rbegin(); it != B.rend(); it++) {
            std::cout << *it << "\n";
        }
    } else std::cout << "green and blue died\n";
}

int main() {
    fast_io();
    int T, n; std::cin >> T; n = T-1; 
    while (T--) {
        if (T!=n) std::cout << "\n";
        solve();
    }
    return 0;
}
