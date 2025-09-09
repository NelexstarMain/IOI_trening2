#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
 
    vector <long long> pa(n + 1), pb(m + 1);
    for (int i = 0; i < n; i++)
        pa[i + 1] = pa[i] + a[i];
    for (int i = 0; i < m; i++)
        pb[i + 1] = pb[i] + b[i];
 
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
 
        int l = max(0, z - y);
        int r = min(z, x);
        while (l + 2 < r) {
            int m1 = (l + l + r) / 3;
            int m2 = (l + r + r) / 3;
            if (pa[m1] + pb[z - m1] > pa[m2] + pb[z - m2]) {
                r = m2;
            } else {
                l = m1;
            }
        }
 
        long long s = 0;
        for (int i = l; i <= r; i++)
            s = max(s, pa[i] + pb[z - i]);
 
        cout << s << '\n';
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}