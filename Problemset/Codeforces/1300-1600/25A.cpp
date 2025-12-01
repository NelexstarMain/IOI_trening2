#include <iostream>
#include <vector>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    int even = 0, odd = 0;
    int last_even = -1, last_odd = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even++;
            last_even = i + 1; 
        } else {
            odd++;
            last_odd = i + 1;
        }
    }

    cout << ((even == 1) ? last_even : last_odd) << "\n";
}

int main() {
    fast_io();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
