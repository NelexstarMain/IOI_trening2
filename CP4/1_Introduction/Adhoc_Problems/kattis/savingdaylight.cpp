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

int time_to_m(std::string s) {
    int m, h;
    if (s.size() == 4) {
        h = s[0]-'0';
        m = (s[2]-'0')*10 + s[3]-'0';
    } else {
        h = (s[0]-'0')*10 + s[1]-'0';
        m = (s[3]-'0')*10 + s[4]-'0';
    }
    return 60*h+m;
}

pii th(int m) {
    int h = m/60;
    int mi = m%60;
    return {h, mi};
}

int main() {
    fast_io();
    std::string a, b, c, start, end; 
    while (std::cin >> a >> b >> c >> start >> end) {
        pii res = th((time_to_m(end) - time_to_m(start)));
        std::cout << a << " " << b << " " << c << " " << res.first << " hours " << res.second << " minutes\n";
    }
    return 0;
}

