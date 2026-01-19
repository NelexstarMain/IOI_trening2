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
    int n; 
    while (std::cin >> n && n > 0) {
        std::vector<int> V(101, 0);
        for (int i = 0; i < n; i++) {
            int c; std::cin >> c;
            V[c]++;
        }
        std::string s = "";
        for (int i = 0; i < 101; i++) {
            while (V[i] > 0) {
                s += std::to_string(i) + " ";
                V[i]--;
            }
        }
        s.erase(s.end()-1);
        std::cout << s << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
