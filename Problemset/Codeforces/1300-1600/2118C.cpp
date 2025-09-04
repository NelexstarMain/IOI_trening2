#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    int score = 0;
    vector<ll> wholeBeauty;

    for (int i = 0; i < n; i++) {
        bitset<64> b(a[i]);
        for (int j = 63; j >= 0; --j) {
            if (b[j] == 0) {
                wholeBeauty.push_back(1ULL << j); 
            } else {
                score++; 
            }
        }
    }


    sort(wholeBeauty.begin(), wholeBeauty.end());
    
    for (ll x : wholeBeauty) {
        if (k >= x) {
            score++;
            k -= x;
        }
    }

    cout << score << "\n";
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
