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
    int sum = 0;
    int start = ((s.size()%2==0) ? 0: 1);
    for (int i = 0; i < s.size(); i++) {
        if (i%2==start) {
            int num = s[i] - '0';
            num *= 2;
            if (num > 9) num = num-9;
            sum += num;
        } else {
            int num = s[i] - '0';
            sum += num;
        }
    }
    std::cout << ((sum%10==0)?"PASS":"FAIL") << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
