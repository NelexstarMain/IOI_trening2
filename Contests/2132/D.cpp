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
    ll n, k;
    cin >> n >> k;
    ll rounds = 1;
    std::vector<int> used;
    ll total_cost = 0;


    while (n > 0) {
        if (rounds > k) {
            std::cout << -1 << "\n";
            return;
        }
        auto it = upper_bound(powers.begin(), powers.end(), n);
        --it;
        int idx = it - powers.begin(); 
        total_cost += costs[idx];
        n -= powers[idx];
        used.push_back(idx);
        rounds++;
    }
    rounds = k-rounds+1;

    for (int x: used) {
        if (rounds > 0) {
            int biggest = x;
            int t = 1;
            int j = 0;
            while ((t*3 - 1) <= rounds && j+1 <= biggest) {
                t = t*3;
                j++;
            } 
            int newcost = t*costs[biggest-j] - costs[biggest];
            total_cost += newcost;
            rounds -= t-1;
        }
        
        
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
