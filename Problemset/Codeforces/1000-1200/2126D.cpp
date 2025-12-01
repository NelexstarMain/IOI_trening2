#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n,k;
    cin >> n >> k;
    pair <int,pair <int,int> > p[n + 1];
    for(int i = 1;i <= n;i++) cin >> p[i].first >> p[ыi].second.first >> p[i].second.second;
    sort(p + 1,p + n + 1);
    int cur = k;
    for(int i = 1;i <= n;i++) {
      if(p[i].first > cur) break;
      cur = max(cur,p[i].second.second);
    }
    cout << cur << endl;
  }
}