#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        if(x==1 || x==n) {
            cout << "1\n";
            continue;
        }
        x--;
        int inf = 1e9;
        int lf=-inf, rg=inf;
        for(int i=x-1; i>=0; i--)
            if(s[i]=='#') {
                lf=i;
                break;
            }
        for(int i=x+1; i<n; i++)
            if(s[i]=='#') {
                rg=i;
                break;
            }
        if(lf==-inf && rg==inf) {
            cout << "1\n";
            continue;
        }
        cout << max(min(x+1, n-rg+1), min(lf+2, n-x)) << '\n';
    }
    return 0;
}