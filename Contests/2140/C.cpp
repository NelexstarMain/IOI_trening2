#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) {
            initial_sum += a[i];
        } else {
            initial_sum -= a[i];
        }
    }

    long long max_gain = 0;


    if (n > 1) {
        long long gain1_max = 0;
        if (n % 2 != 0) {
            gain1_max = n - 1;
        } else { 
            gain1_max = n - 2;
        }
        max_gain = max(max_gain, gain1_max);
    }
    

    long long min_X_odd = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) { 
            long long current_X_odd = (long long)i + 2 * a[i - 1];
            min_X_odd = min(min_X_odd, current_X_odd);
        } else { 
            if (min_X_odd != LLONG_MAX) {
                long long current_X_even = (long long)i + 2 * a[i - 1];
                max_gain = max(max_gain, current_X_even - min_X_odd);
            }
        }
    }
    

    long long min_Y_even = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) { 
            long long current_Y_even = (long long)i - 2 * a[i - 1];
            min_Y_even = min(min_Y_even, current_Y_even);
        } else { 
            if (min_Y_even != LLONG_MAX) {
                long long current_Y_odd = (long long)i - 2 * a[i - 1];
                max_gain = max(max_gain, current_Y_odd - min_Y_even);
            }
        }
    }

    cout << initial_sum + max_gain << endl;
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