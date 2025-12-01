#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>    
#include <cmath>      

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int& x : values) cin >> x;

    vector<vector<int>> a = {{0, 0}};
    vector<vector<int>> b;

    for (int i = 0; i < n; i++) {
        for (auto& p : a) {
            int x = p[0];
            int y = p[1];
            b.push_back({x + values[i], y});
            b.push_back({x, y + values[i]});
        }
        a = b;
        b.clear();
    }

    int res = INT_MAX;
    for (auto& p : a) {
        int x = p[0], y = p[1];
        res = min(res, abs(x - y));
    }
    cout << res << '\n';

    return 0;
}
