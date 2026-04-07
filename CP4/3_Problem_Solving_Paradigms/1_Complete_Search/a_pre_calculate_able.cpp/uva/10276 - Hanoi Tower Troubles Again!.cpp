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

const int INF = 100000;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bitset<INF*2+1> Check;
map<int, int> A;

void prec() {
    int i = 1;
    while (i*i <= INF*2) { Check[i*i] = true; i++; }
    for (int i=1; i<=50; i++) {
        vector<int> V(i);
        for (int j=1; j<INF; j++) {
            bool found = false;
            for (int &x: V) {
                if (Check[x+j] || x == 0) {
                    x = j; found = true;
                    break;
                }
            }
            if (!found) {
                A[i] = j-1;
                break;
            }
        }
    }
}

void solve() {
    int N; cin >> N;
    cout << A[N] << "\n";
}

int main() {
    fast_io();
    prec();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
