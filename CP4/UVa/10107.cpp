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
    ll c;
    std::vector<ll> a;
    while (std::cin >> c) {
        // c = std::stoll(c);
        a.PB(c);
        std::sort(ALL(a));
        int n = SIZE(a);
        if (SIZE(a)%2==0) std::cout << (a[n / 2] + a[n / 2 - 1]) / 2 << "\n"; 
        else std::cout << a[n / 2] << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
