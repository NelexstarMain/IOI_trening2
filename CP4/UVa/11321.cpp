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

bool compare(int a, int b, int m) {
    int ra = a % m, rb = b % m;
    if (ra != rb) return ra < rb;

    bool ao = abs(a % 2), bo = abs(b % 2);
    if (ao != bo) return ao;
    if (ao) return a > b;
    return a < b;
}

void solve() {
    int n, m;
    while (std::cin >> n >> m || n > 0) {
        std::vector<int> a(n); for (auto& x: a) std::cin >> x;
        std::sort(ALL(a), [&](int a, int b) { return compare(a, b, m); });
        std::cout << n << " " << m << "\n";
        for (int x: a) std::cout << x << "\n";
    }
    std::cout << "0 0";
    

}

int main() {
    fast_io();
    solve();
    return 0;
}
