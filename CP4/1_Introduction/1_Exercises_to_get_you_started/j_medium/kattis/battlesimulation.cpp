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
    std::string s; std::cin >> s;
    std::string res;
    for (int i = 0; i < s.size();) {
        

        if (i+2 < s.size() && s[i]!=s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2]) {
                res += 'C';
                i += 3;

        } else {
            if (s[i] == 'R') {
                res += 'S';
            } else if (s[i] == 'B') {
                res += 'K';
            } else {
                res += 'H';
            }
            i++;
        }
    }
    std::cout << res;
}

int main() {
    fast_io();
    solve();
    return 0;
}
