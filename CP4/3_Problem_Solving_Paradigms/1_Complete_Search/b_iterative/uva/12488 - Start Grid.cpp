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
    int N;
    while (cin >> N) {
        int A[25], B[25], C[25], D[25], CO=0;
        for (int i=1; i<=N; i++) { cin >> A[i]; C[A[i]] = i; }
        for (int i=1; i<=N; i++) { cin >> B[i]; D[B[i]] = i; }
        for (int i=1; i<=N; i++) {
            set<int> V; 
            for (int j=1; j<C[i]; j++) V.insert(A[j]);
            for (int j=1; j<D[i]; j++) if (V.find(B[j]) != V.end()) V.erase(B[j]);
            CO+=SIZE(V);
            // cout << SIZE(V) << "\n";
        }        
        cout << CO << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
