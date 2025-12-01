#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> powers;
vector<ll> costs;

void precompute() {
    ll num = 1;
    ll x = 0;
    while (num <= 1e9 + 10) {
        powers.push_back(num);
        if (x == 0) {
            costs.push_back(3);
        } else {
            costs.push_back(3 * num + x * (num / 3));
        }
        if (num > 1e9 / 3) break;
        num *= 3;
        x++;
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> deal_counts(powers.size(), 0);
    ll total_cost = 0;
    ll deals = 0;

    ll temp_n = n;
    int max_idx = -1;
    for (int i = powers.size() - 1; i >= 0; --i) {
        if (temp_n >= powers[i]) {
            ll count = temp_n / powers[i];
            deal_counts[i] = count;
            deals += count;
            total_cost += count * costs[i];
            temp_n %= powers[i];
            if (max_idx == -1) {
                max_idx = i;
            }
        }
    }

    if (temp_n > 0) { 
        cout << -1 << "\n";
        return;
    }

    if (deals > k) {
        cout << -1 << "\n";
        return;
    }

    ll extra_deals = k - deals;

    for (int i = max_idx; i > 0 && extra_deals >= 2; --i) {
        ll can_convert = deal_counts[i];
        if (can_convert == 0) continue;

        ll num_conversions = min(can_convert, extra_deals / 2);
        
        total_cost -= num_conversions * (costs[i] - 3 * costs[i-1]);
        extra_deals -= num_conversions * 2;
    }

    cout << total_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}