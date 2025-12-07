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
    std::unordered_set<ll> uniq;
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        ll curr; std::cin >> curr;
        uniq.insert(curr);
    }
    if (uniq.find(uniq.size()) != uniq.end()) {
        std::cout << uniq.size() << "\n";
        return;
    } else {
        ll x = -INF;
        int besty = -INF;
        for (ll y: uniq) {
            if (uniq.size() < y) {
                if (y-uniq.size() < x) {
                    x = y-uniq.size();
                    besty = y;
                }
            }
        };
        std::cout << besty << "\n";
    }
    
    
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
