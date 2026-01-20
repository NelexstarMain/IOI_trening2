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

std::string minu(std::string f, std::string s) {
    reverse(ALL(f));
    reverse(ALL(s));

    int n = SIZE(f), m = SIZE(s);
    std::string res = "";
    int borrow = 0;
    for (int i = 0; i < n; i++) {
        int a = f[i] - '0';
        int b = (i < m) ? s[i] - '0' : 0;
        int sub = a - b - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res += (char)(sub + '0');
    }
    while (SIZE(res) > 1 && res.back() == '0') res.pop_back();
    reverse(ALL(res));
    return res;
}

void solve() {
    std::string n; 
    while (std::cin >> n && n != "0") {
        while (SIZE(n) > 10) {
            int last = n[SIZE(n)-1]-'0';
            n = minu(n.substr(0,SIZE(n)-1), std::to_string((last*5))); 
        }
        std::cout << (std::stoll(n)%17==0) << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
