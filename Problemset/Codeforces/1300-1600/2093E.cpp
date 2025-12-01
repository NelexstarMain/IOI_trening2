#include <bits/stdc++.h>

using namespace std;

vector<int> nums(2e5 + 5, 0);

bool check(vector<int>& v, int k, int m)
{
    int cnt = 0;
    int cur_mex = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= v.size() + 1) {
            nums[v[i]] = 1;
        }
        while (nums[cur_mex]) {
            cur_mex++;
        }
        if (cur_mex >= m) {
            cnt++;
            for (int j = 0; j < min(m + 1, (int)v.size() + 2); j++) {
                nums[j] = 0;
            }
            cur_mex = 0;
        }
    }
    for (int j = 0; j < v.size() + 2; j++) {
        nums[j] = 0;
    }
    return cnt >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0;
    int r = 1e9;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(v, k, m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}

signed main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}