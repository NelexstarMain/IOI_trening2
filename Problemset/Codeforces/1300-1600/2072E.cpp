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

// usuwamy początkową wielkość, będziemy push_backować
std::vector<int> list_vals;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void precompute() {
    list_vals.reserve(500);
    for (int n = 1; n <= 500; n++) {
        list_vals.push_back((n * (n - 1)) / 2);
    }
}

void solve() {
    int k;
    cin >> k;

    std::vector<int> solution;

    int left = 0, right = (int)list_vals.size() - 1;
    int ans = -1;

    while (k > 0) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (list_vals[mid] <= k) {
                ans = mid;
                left = mid + 1; // próbujemy znaleźć większy, ale ≤ k
            } else {
                right = mid - 1;
            }
        }

        if (ans != -1) {
            solution.push_back(ans);
            k -= list_vals[ans];
        }
    }

    int count = 0;
    for (auto x : solution) {
        std::cout << list_vals[x] << " ";
    }

}

int main() {
    fast_io();
    precompute();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
