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

bool leap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int days_in_month(int y, int m) {
    static int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && leap(y)) return 29;
    return d[m - 1];
}

ll toMin(const string& date, const string& time) {
    int y = stoi(date.substr(0, 4)); int m = stoi(date.substr(5, 2)); int d = stoi(date.substr(8, 2));
    int h = stoi(time.substr(0, 2)); int mi = stoi(time.substr(3, 2));
    ll days = 0;
    for (int i = 1; i < y; i++)
        days += leap(i) ? 366 : 365;
    for (int i = 1; i < m; i++)
        days += days_in_month(y, i);
    days += (d - 1);
    return days * 24 * 60 + h * 60 + mi;
}

void solve() {
    std::map<int, int> a;
    std::set<int> p;
    int m = 0;
    int b, c; std::cin >> b >> c;
    for (int i = 0; i < b; i++) {
        std::string code, sd, st, ed, et; std::cin >> code >> sd >> st >> ed >> et;
        a[toMin(sd, st)]++; p.insert(toMin(sd, st));
        a[toMin(ed, et)+c]--; p.insert(toMin(ed, et)+c);
    }

    int curr = 0;
    for (int x: p) {
        curr += a[x];
        m = std::max(m, curr);
    }
    std::cout << m << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
