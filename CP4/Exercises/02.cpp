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
    std::string T; std::cin >> T;
    std::string P; std::cin >> P;
    std::vector<int> pos;
    for (int i = 0; i <= T.size() - P.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < P.size(); ++j) {
            if (T[i+j] != P[j]) {
                ok = false;
                break;
            }
        }
        if (ok) pos.push_back(i);
    }

    for (int p : pos) {
        std::cout << p << " ";
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
