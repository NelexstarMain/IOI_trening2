#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        bool ok = true;
        long long carry = 0; 

        for (int i = 0; i < n; i++) {
            carry += a[i];
            if (carry < 0) {
                ok = false;
                break;
            }
            carry -= i;
        }

        cout << (ok && carry == 0 ? "YES\n" : "NO\n");
    }
}
