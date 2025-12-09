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

int time_to_sec(std::string s) {
    int h = (s[0]-'0')*10+(s[1]-'0');
    int m = (s[3]-'0')*10+(s[4]-'0');
    int se = (s[6]-'0')*10+(s[7]-'0');
    return (h*3600+m*60+se);
}

void solve() {
    std::string f, s; std::cin >> f >> s;
    int ft = time_to_sec(f), st = time_to_sec(s);
    if (st <= ft) {
        st += (24*3600);
    }
    int curr = st - ft;
    int h = curr/3600;
    int m = (curr%3600)/60;
    int se = (curr%3600)%60;
    std::cout << ((h < 10) ? "0" : "") << h << ":" << ((m < 10) ? "0" : "") << m << ":" << ((se < 10) ? "0" : "") << se << "\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}
