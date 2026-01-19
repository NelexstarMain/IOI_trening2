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
    std::string n, k; std::cin >> n >> k;
    std::string res = "1";
    int times = 0;
    while (SIZE(res) < SIZE(n) || (SIZE(res) == SIZE(n) && res < n)) {
        times++;
        int carry = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            int d = (res[i] - '0') * 2 + carry;
            res[i] = char('0' + (d % 10));
            carry = d / 10;
        }
        if (carry) res = char('0' + carry) + res;
    }
    std::string s = std::to_string(times);
    if (SIZE(s) > SIZE(k) || (SIZE(s) == SIZE(k) && s > k)) std::cout << "You will become a flying monkey!\n";
    else std::cout << "Your wish is granted!\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}
