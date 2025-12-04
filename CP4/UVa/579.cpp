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

bool solve() {
    std::string time; std::cin >> time;
    int h, m;
    if (time.size() == 4) {
        h = time[0]-'0';
        m = (int)(time[2]-'0')*10 + time[3]-'0';
    } else {
        h = (int)(time[0]-'0')*10 + (int)(time[1]-'0');
        m = (int)(time[3]-'0')*10 + (int)(time[4]-'0');
    }
    if (h == 0 && m == 0) return false;
    double angle = std::abs(((360.0/60) * m - ((360.0/12 * h) + m*0.5)));
    double res = std::round(1000.0 * std::min(angle, 360.0-angle)) / 1000.0;
    std::cout << std::fixed << std::setprecision(3) << res << "\n";
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}
