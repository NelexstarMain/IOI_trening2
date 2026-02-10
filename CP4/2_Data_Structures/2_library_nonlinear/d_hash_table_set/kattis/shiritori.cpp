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
    int n; std::cin >> n;
    std::unordered_set<std::string> A;
    std::string prev = "";
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        if ((prev == "" || s[0] == prev[SIZE(prev)-1]) && (A.find(s) == A.end())) { prev = s; A.insert(s); }
        else {
            std::cout << "Player " << ((i % 2) + 1) << " lost\n";
            return;
        }
    
    }
    std::cout << "Fair Game\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
