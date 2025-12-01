#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> powers;   
vector<ll> costs;    


void precompute() {
    ll num = 1;
    int x = 0;
    while (num <= 1e9) {
        powers.push_back(num);
        if (x == 0) costs.push_back(3); 
        else costs.push_back(num*3 + x*(num / 3));
        num *= 3;
        x++;
    }
}

void solve() {
    ll n;
    cin >> n;
    ll total_cost = 0;


    while (n > 0) {
        auto it = upper_bound(powers.begin(), powers.end(), n);
        --it;
        int idx = it - powers.begin(); 
        total_cost += costs[idx];
        n -= powers[idx];
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
