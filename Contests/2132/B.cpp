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
    ll n;
    cin >> n;
    vector<ll> solutions;

    ll p = 10;
    while (n >= p + 1) {
        if (n % (p + 1) == 0) {
            solutions.push_back(n / (p + 1));
        }
        p *= 10;
    }

    sort(ALL(solutions));
    if (solutions.empty()) {
        std::cout << "0\n";
        return;
    }
    cout << solutions.size() << "\n";
    for (auto x : solutions) cout << x << " ";
    cout << "\n";
}


int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}