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
    int n, k; 
    cin >> n >> k;
    string s; 
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
            if (cnt >= k) { 
                cout << "NO\n";
                return;
            }
        } else {
            cnt = 0; 
        }
    }


    cout << "YES\n";
    vector<int> ones, zeros;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ones.push_back(i);
        else zeros.push_back(i);
    }

    vector<int> p(n);
    int val = 1;
    for (int idx : ones) p[idx] = val++;
    for (int idx : zeros) p[idx] = val++;
    for (int i = 0; i < n; i++) {
        cout << p[i] << (i + 1 == n ? "\n" : " ");
    }
}


int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}