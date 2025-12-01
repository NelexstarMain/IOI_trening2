#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for(auto &i : g) {
        cin >> i;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(),
    [&](int x, int y) {
        if(g[x][y] == '1') return x < y;
        else return x > y;
    });
    for(auto i : p) cout << i + 1 << " "; cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}