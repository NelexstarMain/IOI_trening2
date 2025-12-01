#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> pts(n);
    vector<int> xs(n), ys(n);

    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
        pts[i] = {xs[i], ys[i]};
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<int> sx = xs, sy = ys;
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());

    int minX = sx[0], maxX = sx[n-1];
    int minX2 = sx[1], maxX2 = sx[n-2];
    int minY = sy[0], maxY = sy[n-1];
    int minY2 = sy[1], maxY2 = sy[n-2];

    long long ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        int Xmin = (pts[i].first == minX ? minX2 : minX);
        int Xmax = (pts[i].first == maxX ? maxX2 : maxX);
        int Ymin = (pts[i].second == minY ? minY2 : minY);
        int Ymax = (pts[i].second == maxY ? maxY2 : maxY);

        long long width = Xmax - Xmin + 1;
        long long height = Ymax - Ymin + 1;
        long long area = width * height;

        if (area <= n - 1) {
            long long need = (n - 1) - area + 1; 

            long long newWidth = width + (need + height - 1) / height;
            long long areaCols = newWidth * height;

            long long newHeight = height + (need + width - 1) / width;
            long long areaRows = newHeight * width;

            area = min(areaCols, areaRows);
        }

        ans = min(ans, area);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while (T--) solve();
}
