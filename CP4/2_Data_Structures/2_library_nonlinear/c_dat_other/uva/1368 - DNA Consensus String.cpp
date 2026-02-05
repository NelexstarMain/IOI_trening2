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
    int n, k; std::cin >> n >> k;
    std::vector<std::string> A;
    for (int i = 0; i < n; i++) {
        std::string c; std::cin >> c;
        A.PB(c);
    }
    std::string res = "";
    int error = 0;
    for (int j = 0; j < k; j++) {
        int maximum = 0;
        std::map<char, int> B;
        for (int i = 0; i < n; i++) {
            B[A[i][j]]++;
            maximum = std::max(maximum, B[A[i][j]]);
        }
        error += (n - maximum);
        for (auto [key, value]: B) {
            if (value == maximum) {
                res += key;
                break;
            }
        }
    }
    std::cout << res << "\n";
    std::cout << error << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();    
    return 0;
}
