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


std::vector<int> mon = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::vector<int> leapmon = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::vector<std::vector<ll>> validdates;

bool isLeap(ll year) {
    if (year%4==0) {
        if (year%100!=0 || year%400==0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool valid(ll d, ll m, ll y) {
    if (m < 1 || m > 12) return false;
    std::vector<int> currmon = ((isLeap(y)) ? leapmon: mon);
    if (d >= 1 && d <= currmon[m-1]) { 
        validdates.PB({d, m, y}); 
        return true;
    } else {
        return false;
    }
}
void solve() {
    validdates.clear();
    ll z, a, b, c; std::cin >> z >> a >> b >> c;
    ll century = z*100;
    valid(a, b, c+century);
    valid(a, c, b+century);
    valid(b, a, c+century);
    valid(c, a, b+century);
    valid(c, b, a+century);
    valid(b, c, a+century);

    std::sort(ALL(validdates), [](std::vector<ll> a, std::vector<ll> b) {
        if (a[2] != b[2]) return a[2] < b[2];
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });
    if (SIZE(validdates) > 0) {
        std::vector<ll> res = validdates[0];
        std::cout << (((res[2]-century) < 10)? "0" : "") << res[2]-century << " " << ((res[1] < 10)? "0" : "") << res[1] << " " << ((res[0] < 10)? "0" : "") << res[0] << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
