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

int t = 1e9;

pii interact() {
    int res = 0, nres = 0;
    std::cout << "? D" << t;
    std::cin << res;
    std::cout << "? D" << t;
    std::cin << res;
    std::cout << "? L" << t;
    std::cin << res;
    std::cout << "? L" << t;
    std::cin << res;
    std::cout << "? R" << t;
    std::cin << nres;
    std::cout << "? R" << t;
    std::cin << nres;
    std::cout << "? R" << t;
    std::cin << nres;
    std::cout << "? R" << t;
    std::cin << nres;
    return {res, nres}
}

void solve() {
    std::vector<pii> points(n);
    int n; std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; std::cin >> x >> y;
        points.push_back({x, y});
    }
    std::sort(ALL(points));
    

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