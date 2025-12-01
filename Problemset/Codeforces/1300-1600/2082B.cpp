#include <iostream>

using namespace std;

using ll = long long;

ll F(ll x, ll n) {
    for (int i = 0; i < n; ++i) {
        if (x == 0) {
            return 0;
        }
        x /= 2;
    }
    return x;
}
ll C(ll x, ll n) {
    for (int i = 0; i < n; ++i) {
        if (x <= 1) {
            return x;
        }
        x = (x + 1) / 2;
    }
    return x;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll x, n, m;
        cin >> x >> n >> m;
        cout << F(C(x, m), n) << " " << C(F(x, n), m) << endl;
    }

    return 0;
}