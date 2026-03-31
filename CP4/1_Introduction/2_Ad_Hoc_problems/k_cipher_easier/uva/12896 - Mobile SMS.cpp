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

std::vector<std::string> b = {" ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve() {
    int n; std::cin >> n;
    std::string res = "";
    std::vector<int> button(n); for (int& x: button) std::cin >> x;
    std::vector<int> times(n); for (int& x: times) std::cin >> x;
    for (int i = 0; i < n; i++) {
        res += b[button[i]][times[i]-1];
    }
    std::cout << res << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
