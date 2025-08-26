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
    int n; 
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> filtered;
    filtered.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            filtered.push_back(arr[i]);
        }
    }

    arr = filtered;
    n = arr.size();

    if (n == 1) {
        std::cout << 1 << "\n";
        return; 
    }

    int peaks = 0;
    for (int i = 1; i < n-1; i++) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            peaks++;
        }
    }
    if (arr[0] > arr[1]) peaks++;
    if (arr[n-1] > arr[n-2]) peaks++;
    std::cout << ((peaks == 0) ? 1 : peaks) << "\n";
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