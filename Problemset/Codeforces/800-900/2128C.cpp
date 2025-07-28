#include <bits/stdc++.h>
using namespace std;
 
bool solve() {
    int N; cin >> N;
    vector<int> B(N);
    for (int &x : B) cin >> x;
    int min_pref = B[0];
    for (int val : B) {
        if (val >= 2*min_pref) return false;
        min_pref = min(min_pref, val);
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}

 