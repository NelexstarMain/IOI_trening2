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
    int n; cin >> n;
    map<string, vector<int>> trips; 

    for (int i = 0; i < n; i++) {
        string country; int year;
        cin >> country >> year;
        trips[country].PB(year);
    }
    for (auto &entry : trips) {
        sort(ALL(entry.second));
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        string country; int t;
        cin >> country >> t;
        cout << trips[country][t - 1] << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
