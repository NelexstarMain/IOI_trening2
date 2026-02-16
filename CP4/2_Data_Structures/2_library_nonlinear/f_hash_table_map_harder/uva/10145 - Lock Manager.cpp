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
    char s; 
    std::map<int, std::set<int>> A;
    std::unordered_map<int, int> B;
    std::unordered_set<int> C;
    while (std::cin >> s && s != '#') {
        int a, b; std::cin >> a >> b;
        bool denied = false;

        if (s == 'X') {
            if (B.find(b) != B.end() && B[b] != a) denied = true;
            else if (A.find(b) != A.end() && SIZE(A) > 1) denied = true;
            
            if (!denied) 

        } else {

        }

    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
