#include <bits/stdc++.h>

using namespace std;

bool craneTouchWall(const pair<double, double> &crane, const pair<double, double> &wallCenter, double r) {
    return (crane.first - wallCenter.first) * (crane.first - wallCenter.first) +
           (crane.second - wallCenter.second) * (crane.second - wallCenter.second) <= r * r + 1e-6;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double l, w, r;
    cin >> l >> w >> n >> r;
    vector<pair<double, double>> wallCenters(4), cranes(n);
    wallCenters[0] = {-l / 2, 0};
    wallCenters[1] = {l / 2, 0};
    wallCenters[2] = {0, -w / 2};
    wallCenters[3] = {0, w / 2};
    for (int i = 0; i < n; ++i) {
        cin >> cranes[i].first >> cranes[i].second;
    }

    int minCrane = INT_MAX;
    for (int i1 = 0; i1 <= n; ++i1) {
        for (int i2 = i1 + 1; i2 <= n + 1; ++i2) {
            for (int i3 = i2 + 1; i3 <= n + 2; ++i3) {
                for (int i4 = i3 + 1; i4 <= n + 3; ++i4) {
                    vector<int> touchWallCount(4);
                    int craneCnt = 0;
                    for (int i = 0; i < n; ++i) {
                        if (i == i1 || i == i2 || i == i3 || i == i4) { 
                            craneCnt++;
                            for (int j = 0; j < 4; ++j) {
                                if (craneTouchWall(cranes[i], wallCenters[j], r)) {
                                    touchWallCount[j]++;
                                }
                            }
                        }
                    }
                    if (*min_element(touchWallCount.begin(), touchWallCount.end()) != 0) {
                        minCrane = min(minCrane, craneCnt);
                    }
                }
            }
        }
    }
    if (minCrane > 40) {
        cout << "Impossible" << endl;
    } else {
        cout << minCrane << endl;
    }
    return 0;
}