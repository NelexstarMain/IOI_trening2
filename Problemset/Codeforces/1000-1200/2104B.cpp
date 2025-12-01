
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
    int n; 
    cin >> n;
    
    vector<ll> arr(n); 
    for (ll& x : arr) {
        cin >> x;
    }

    vector<ll> max_prefix(n);
    ll maxim = 0;
    for (int i = 0; i < n; i++) {
        maxim = max(maxim, arr[i]);
        max_prefix[i] = maxim;
    }

    vector<ll> suffix_sum(n);
    ll sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += arr[i];
        suffix_sum[i] = sum;
    }

    for (int k = 1; k <= n; k++) {
        ll max_possible_sum;

        ll sum_without_move = suffix_sum[n - k];
        max_possible_sum = sum_without_move;

        if (n - k > 0) {
            ll max_val_in_prefix = max_prefix[n - k - 1];
            ll first_of_k = arr[n - k];

            if (max_val_in_prefix > first_of_k) {
                ll sum_of_rest = 0;
                if (k > 1) {
                    sum_of_rest = suffix_sum[n - k + 1];
                }
                ll sum_with_move = sum_of_rest + max_val_in_prefix;
                
                max_possible_sum = max(max_possible_sum, sum_with_move);
            }
        }
        cout << max_possible_sum << " ";
    }
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
