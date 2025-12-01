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

int n, k;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll dp(int cost, std::vector<ll> arr, int k) {
    int c = cost;
    if (k > 0) {
        for (ll x: arr) {
            ll size = (1LL << (x-1));
            if (size <= k) {
                k -= size;
                ll newCost = 1;
                if (x == 1) continue;
                for (int i = x-1; i > 0; --i) {
                    newCost *= i*(x-i);
                    std::cout << "\n" << newCost << "\n";
                }
                c *= newCost;
            } else {
                if (k == 0) {
                    break;
                }
                c *= x;
                k--;
                std::vector<ll> newArr;
                std::cout << "\n";
                for (int i = 1; i < x; i++) {
                    newArr.push_back(i);
                    std::cout << i << " ";
                }
                std::cout << "\n";
                c = dp(c, newArr, k);
            }
        
        }
    } 
    
    return c;
}


void solve() {
    std::cin >> n >> k;
    int cost = 1;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(ALL(a));
    for (ll x: a) std::cout << x << " ";
    std::cout << "\n";
    ll result = dp(1, a, k);
    std::cout << result << "\n";

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