#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    // Używamy long long (ll) dla czasów, żeby być bezpiecznym
    std::vector<pll> JOHNT(10);
    std::vector<std::vector<ll>> parameters(10, std::vector<ll>(3));
    std::vector<ll> last(10, -1e18); // Inicjalizacja małą liczbą

    for (int i = 0; i < 10; i++) {
        ll n, k; std::cin >> n >> k;
        JOHNT[i] = {n, k};
    }
    
    ll t = 0;
    
    for (int i = 0; i < 10; i++) {
        ll a, b, c; std::cin >> a >> b >> c;
        parameters[i] = {a, b, c};
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 10; i++) {
            if (j > 0) {
                t = std::max(t, last[i] + JOHNT[i].second);
            }
            
            ll use = parameters[i][0];
            ll rec = parameters[i][1];
            ll &start = parameters[i][2]; 

            while (start + use + rec <= t) {
                start += (use + rec);
            }
            if (start > t) {
                t += JOHNT[i].first;
                if (t > start) start = t + use + rec;
                else start = start + use + rec;
            } else {
                if (t < start + use) {
                    t = start + use;
                }
                
                t += JOHNT[i].first;
                start = t + use + rec;
            }

            last[i] = t;
            if (j < 2 || i < 9) {
                t += JOHNT[i].second;
            }
        }
    }
    std::cout << last[9] << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}