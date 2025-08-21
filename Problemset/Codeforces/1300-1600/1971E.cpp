
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
#define ALL(a) (a).begin(), (a).end()

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k), b(k);
    vector<pii> points;
    points.push_back({0, 0});

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    for (int i = 0; i < k; i++)
        points.push_back({a[i], b[i]});

    sort(ALL(points));

    for (int _ = 0; _ < q; _++) {
        int x; cin >> x;
        auto it = lower_bound(ALL(points), make_pair(x, 0));
        int idx = it - points.begin();

        if (it != points.end() && points[idx].first == x) {
            cout << points[idx].second << " ";
            continue;
        }

        if (it == points.end()) {
            int idx_prev = points.size() - 2;
            int idx_next = points.size() - 1;
            long long dx = points[idx_next].first - points[idx_prev].first;
            long long dt = points[idx_next].second - points[idx_prev].second;
            long long time = points[idx_next].second + 1LL * (x - points[idx_next].first) * dt / dx;
            cout << time << " ";
            continue;
        }

        int idx_prev = idx - 1;
        long long dx = points[idx].first - points[idx_prev].first;
        long long dt = points[idx].second - points[idx_prev].second;
        long long time = points[idx_prev].second + 1LL * (x - points[idx_prev].first) * dt / dx;
        cout << time << " ";
    }
    cout << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
