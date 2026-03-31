#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

void solve() {
    int n; cin >> n;
    vector<int> indx;
    vector<string> us;
    for (int i = 0; i < n; i++) {
        string c; cin >> c;
        if (c != "?") indx.push_back(i);
        us.push_back(c);
    }

    if (indx.empty()) return; 

    for (int i = 0; i < SIZE(indx) - 1; i++) {
        int b = indx[i];
        int cu = indx[i+1];
        if ((cu - b) % 2 == 0) {
            int mid = (b + cu) / 2;
            us[mid] = "middle of " + us[b] + " and " + us[cu];
        }
    }

    for (int i = 0; i < SIZE(indx); i++) {
        int start = indx[i];
        for (int j = start + 1; j < n; j++) {
            if (us[j] != "?") break;
            if (i + 1 < SIZE(indx)) {
                int next_obj = indx[i+1];
                if (j - start >= next_obj - j) break; 
            }
            
            us[j] = "right of " + us[j-1];
        }
    }
    for (int i = SIZE(indx) - 1; i >= 0; i--) {
        int start = indx[i];
        for (int j = start - 1; j >= 0; j--) {
            if (us[j] != "?") break;

            if (i - 1 >= 0) {
                int prev_obj = indx[i-1];
                if (start - j >= j - prev_obj) break;
            }

            us[j] = "left of " + us[j+1];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << us[i] << (i == n - 1 ? "" : " ");
    // }
    // cout << endl;
    int hm; std::cin >> hm;
    for (int i = 0; i < hm; i++) {
        int curr; std::cin >> curr;
        std::cout << us[curr-1] << "\n";
    }
}

int main() {
    solve();
    return 0;
}