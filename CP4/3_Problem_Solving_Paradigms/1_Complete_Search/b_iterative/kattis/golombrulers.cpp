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

void solve(string S) {
    vector<int> A;
    stringstream ss(S); int x;
    int M = -INF;
    while (ss >> x) { A.PB(x); M=max(M, x); }
    // for (int x: A) cout << x << "\n"; 
    int N=SIZE(A);
    set<int> D;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int diff = (abs(A[i]-A[j]));
            if (D.find(diff) != D.end()) {
                cout << "not a ruler\n";
                return;
            }
            D.insert(diff); 
        }
    }
    vector<int> R;
    for (int i=1; i<M; i++) {
        if (D.find(i) == D.end()) R.PB(i);
    }
    if (SIZE(R)) { cout << "missing"; for (int x: R) cout << " " << x; }
    else cout << "perfect";
    cout << "\n";

}

int main() {
    fast_io();
    string S; 
    while (getline(cin, S)) solve(S);
    return 0;
}
