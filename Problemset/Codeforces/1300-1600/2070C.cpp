
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0;
    int right = *std::max_element(a.begin(), a.end());
    int res = -1;

    auto check = [&](int d) -> bool {
        char last = 'R';
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > d) {
                if (s[i] == 'B' && last == 'R') cnt++;
                last = s[i];
            }
        }
        return cnt <= k;
    };

    while (left <= right) {
        int m = (left + right) / 2;
        if (check(m)) {
            res = m;
            right = m - 1;
        } else {
            left = m + 1;
        }
    }

    cout << res << "\n";
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
