#include <bits/stdc++.h>
#include <chrono>

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
    int n; std::cin >> n;
    std::unordered_map<ll, int> timestamps;
    std::vector<ll> days;

    ll res = 0;
    int count = 0;

    std::tm start = {};
    start.tm_year = 0;
    start.tm_mon = 0;
    start.tm_mday = 1;
    std::time_t t1 = std::mktime(&start);
    for (int i = 0; i < n; i++) {
        int y, m, d, c; std::cin >> d >> m >> y >> c;
        std::tm end = {};
        end.tm_year = y - 1900;
        end.tm_mon = m-1;
        end.tm_mday = d;
        std::time_t t2 = std::mktime(&end);

        ll diff = std::difftime(t2, t1) / (60*60*24);
        timestamps[diff] = c;
        days.PB(diff);
    }
    std::sort(ALL(days));
    ll before = days[0];

    for (auto x: days) std::cout << x << " ";
    std::cout << "\n";
    for (int i = 1; i < days.size(); i++) {
        if (days[i] == before+1) {
            res += timestamps[days[i]];
            res -= timestamps[before];
            count++;
        }
        before = days[i];
    }
    std::cout << count << " " << res << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}


// Niedziała problemy z bibotekom