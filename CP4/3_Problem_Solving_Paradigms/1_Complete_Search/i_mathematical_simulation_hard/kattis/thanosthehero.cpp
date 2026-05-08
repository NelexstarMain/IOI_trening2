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
    int N; cin >> N;
    ll count=0;
    vector<int> A(N); for (int &x: A) cin >> x;
    for (int i=N-2; i>=0; --i) {
        if (A[i]>=A[i+1]) {
            if (A[i+1]>0) {
                count+=(A[i]-A[i+1]+1);
                A[i]=A[i+1]-1;

            } else {
                cout << "1\n";
                return;
            }
        }
    }
    cout << count << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
