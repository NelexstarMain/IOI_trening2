#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    long long total = 0, best_extra = -1e9;
    for (int i = 0; i < n; i++) {
        total += max(a[i], b[i]);
        best_extra = max(best_extra, (long long) min(a[i], b[i]));
    }

    cout << total + best_extra << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
