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

bool solve() {
    int x = 0, y = 11;
    while (true) {
        int n; std::cin >> n;
        if (n == 0) return false;
        std::string s, t; std::cin >> s >> t;
        s += t;
        if (s == "toohigh") {
            y = std::min(y, n);
        } else if (s == "toolow") {
            x = std::max(x, n);
        } else if (s == "righton") {
            if (x < n && n < y) {
                std::cout << "Stan may be honest\n";
                break;
            } else {
                std::cout << "Stan is dishonest\n";
                return true;
            }
        }
    }
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}
