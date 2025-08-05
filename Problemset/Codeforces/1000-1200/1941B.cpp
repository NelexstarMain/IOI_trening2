#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long start = a[0];

    for (int i = 1; i < n - 1; i++) {
        if (a[i] < 2 * start || a[i + 1] < start) {
            cout << "NO\n";
            return;
        }

        a[i - 1] -= start; 
        a[i]     -= 2 * start;
        a[i + 1] -= start;


        start = a[i];
    }

    for (auto x : a) {
        if (x != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
}
