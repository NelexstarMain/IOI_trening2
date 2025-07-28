#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--) {
        int N, C;
        cin >> N >> C;
        vector<ll> A(N);
        for (ll &x : A) cin >> x;
        sort(A.rbegin(), A.rend()); 
        int saved = 0;
        for (ll x : A) {
            if (x*(1LL << saved) <= C) {
                ++saved;
            }
        }
        cout << N - saved << '\n';
    }
}