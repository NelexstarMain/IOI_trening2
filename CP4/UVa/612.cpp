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

int countInversions(const string& s) {
    int count = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) count++; 
        }
    }
    return count;
}

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<std::string, pii>> a;
    for (int i = 0; i < m; i++) {
        std::string curr; std::cin >> curr;
        a.PB({curr, {countInversions(curr), i}});
    }
    std::sort(ALL(a), [](std::pair<std::string, pii>& f, std::pair<std::string, pii>& s) {
        if (f.S.F != s.S.F) return f.S.F < s.S.F;
        else return f.S.S < s.S.S;
    });
    for (auto x: a) std::cout << x.F << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) {
        solve();
        if (T > 0) std::cout << "\n";
    }
    return 0;
}
