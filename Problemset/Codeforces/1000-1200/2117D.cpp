#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for(auto &it : v) cin >> it;

    long long diff = v[1] - v[0];
    bool bad = 0;
    for(int i = 2; i < n; i++) if(diff != v[i] - v[i - 1]) bad = 1;
    
    if(bad) {
        cout << "NO" << endl;
        return;
    }
    
    for(int i = 0; i < n; i++)
        v[i] = v[i] + (diff < 0 ? diff * (n - i) : -diff * (i + 1));
        
    cout << (v[0] >= 0 && v[0] % (n + 1) == 0 ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}