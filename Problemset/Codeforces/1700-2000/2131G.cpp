#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

std::vector<int> pre;

void precount() {
    pre.push_back(1);
    int a = 1;
    for (int i = 0; i < 30; i++) {
        pre.push_back()
    }

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for (int &x : S) cin >> x;

    

    cout << score << "\n";
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
