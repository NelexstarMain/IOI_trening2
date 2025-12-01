#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ha = c - a, hb = d - b;

    if (a <= 2 + 2*b && b <= 2 + 2*a &&
        ha <= 2 + 2*hb && hb <= 2 + 2*ha) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
