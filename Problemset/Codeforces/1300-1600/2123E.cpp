#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    set<int> excl;
    for(int i=0; i<=n; i++)
        excl.insert(i);
    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
        excl.erase(a[i]);
    }
    map<int, vector<int>> invfreq;
    for(pair<int, int> p : freq)
        invfreq[p.second].push_back(p.first);
    int mex = *excl.begin();
    set<int> vals;
    vals.insert(mex);
    for(int k=0; k<=n; k++){
        vals.erase(n-k+1);
        for(int i : invfreq[k])
            if(i <= min(mex, n-k))
                vals.insert(i);
        cout << vals.size() << (k != n ? ' ' : '\n');
    }
}
 
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}