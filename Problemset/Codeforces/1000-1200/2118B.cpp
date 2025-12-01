#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        cout << 2*n-1 << "\n";
        for (int i = 1; i < n; i++) {
            cout << i << " " << 1 << " " << i << "\n";
            cout << i << " " << i+1 << " " << n << "\n";
        }
        cout << n << " 1 " << n << "\n";
    }
    return 0;
}