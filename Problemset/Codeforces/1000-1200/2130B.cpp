#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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


void solve(){
    int n, k, tmp;
    cin >> n >> k;
    vector<int> a(3);
    for(int i=0; i<n; i++){cin >> tmp; a[tmp]++;}
    if(k == a[1] + 2*a[2] || k >= a[1] + 2*a[2] + 2){cout << -1 << '\n'; return;}
    for(int i=0; i<a[0]; i++) cout << 0 << ' ';
    for(int i=0; i<a[2]; i++) cout << 2 << ' ';
    for(int i=0; i<a[1]; i++) cout << 1 << ' ';
    cout << '\n';
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