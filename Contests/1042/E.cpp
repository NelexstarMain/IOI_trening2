#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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
    std::vector<int> a(n), b(n);
    for (int& x: a) std::cin >> x;
    for (int& x: b) std::cin >> x;

    if (a[n-1] != b[n-1]) {
        std::cout << "NO\n";
        return;
    }

    for (int i = n-2; i >= 0; --i) {
        if (b[i] == (a[i] ^ b[i+1]) || b[i] == a[i] || b[i] == (a[i] ^ a[i+1])) {
            continue;
        } else {
            std::cout << "NO\n";
            return;
        }

    }

    std::cout << "YES\n";
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