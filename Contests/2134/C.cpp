#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long INF = 2e14 + 7;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long initial_odd_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) {
            initial_odd_sum += a[i];
        }
    }

    long long new_odd_sum = 0;
    long long x_prev = 0;
    int m = (n + 1) / 2;

    for (int k = 1; k <= m; ++k) {
        int i_odd = 2 * k - 2;
        int i_prev_even = 2 * k - 3;
        int i_curr_even = 2 * k - 1;

        long long val_odd = a[i_odd];
        long long val_prev_even = (i_prev_even >= 0) ? a[i_prev_even] : INF;
        long long val_curr_even = (i_curr_even < n) ? a[i_curr_even] : INF;


        if (k == m && n % 2 != 0) {
            val_curr_even = INF;
        }
        
        long long x_k = max(min(min(val_odd, val_prev_even - x_prev), val_curr_even), 0LL);

        new_odd_sum += x_k;
        x_prev = x_k;
    }

    cout << initial_odd_sum - new_odd_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}