#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int wtoi(string A) {
    int c=0;
    for (char x: A) {
        c*=32; c+=(int)(x-'a'+1);
    }
    return c;
}

void solve() {
    string l;
    while (getline(cin, l)) {
        cout << l << "\n";
        stringstream ss(l);
        string word; vector<int> W;
        while (ss >> word) W.PB(wtoi(word));
        bool colisions=true;
        int n=SIZE(W);
        ll C=*min_element(ALL(W));
        while (colisions) {
            colisions=false;
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++) {
                    if ((C/W[i])%n==(C/W[j])%n) {
                        C=min((C/W[i]+1)*W[i], (C/W[j]+1)*W[j]);
                        colisions=true;
                        break;
                    }
                }
                if (colisions) break;
            }
        }
        cout << C << "\n\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
