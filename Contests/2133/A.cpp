#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    unordered_set<int> seen;
    bool has_duplicate = false;

    for (int x : arr) {
        if (seen.count(x)) {
            has_duplicate = true;
            break;
        }
        seen.insert(x);
    }

    if (has_duplicate) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
