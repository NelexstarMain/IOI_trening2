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
    int n; std::cin >> n;
    int m = 0;
    std::unordered_map<int, int> a;
    for (int i = 0; i < n; i++) {
        int c; std::cin >> c;
        if (a[c] > 0) {
            a[c]--;
            if (c-1 > 0) a[c-1]++;
        } else {
            m++;
            if (c-1 > 0) a[c-1]++;
        }
    }
    std::cout << m << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
