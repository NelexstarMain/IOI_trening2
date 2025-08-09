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
    int n, k; std::cin >> n >> k;
    int maximum = 0;
    std::vector<std::vector<double>> books;
    std::vector<int> prices(n), pages(n);
    for (int& x: prices) std::cin >> x;
    for (int& x: pages) std::cin >> x;
    for (int i = 0; i < n; i++) {
        books.push_back({prices[i]/pages[i], prices, pages})
    }
    std::sort(ALL(books));
    for (int i = 0; i<n; i++) {
        if (k <= books[i][1]) {
            k -= books[i][1];
            maximum += books[i][2];
        }
    }

}

int main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}