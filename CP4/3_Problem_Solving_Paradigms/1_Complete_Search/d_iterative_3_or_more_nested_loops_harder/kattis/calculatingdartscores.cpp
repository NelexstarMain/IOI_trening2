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

string change(int N) {
    if (N%3==0) return ("triple " + to_string(N/3));
    else if (N%2==0) return ("double " + to_string(N/2));
    else return ("single " + to_string(N));
}

void solve() {
    vector<int> A; for (int i=1; i<=20; i++) { A.PB(i); A.PB(i*2); A.PB(i*3); }
    A.PB(0);
    int N, M=SIZE(A); cin >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<M; k++) {
                if ((A[i]+A[j]+A[k])==N) {
                    if (A[i]!=0) cout << change(A[i]) << "\n";
                    if (A[j]!=0) cout << change(A[j]) << "\n";
                    if (A[k]!=0) cout << change(A[k]) << "\n";
                    return ;
                }
            }
        }
    }
    cout << "impossible\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
