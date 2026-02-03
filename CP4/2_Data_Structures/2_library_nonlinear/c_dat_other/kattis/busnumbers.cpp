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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end()); 

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j] + 1) {
            j++;
        }
        if (i > 0) cout << " ";
        int len = j - i + 1;
        if (len >= 3) {
            cout << a[i] << "-" << a[j];
            i = j; 
        } else {
            cout << a[i];
        }
    }
    cout << endl;
}

int main() {
    fast_io();
    solve();
    return 0;
}
