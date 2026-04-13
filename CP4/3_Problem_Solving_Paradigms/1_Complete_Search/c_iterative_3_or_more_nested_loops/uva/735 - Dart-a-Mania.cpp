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
    set<int> B;
    for (int i=1; i<=20; i++) { B.insert(i); B.insert(i*2); B.insert(i*3); }
    B.insert(50); B.insert(0); vector<int> A; for (int x: B) A.PB(x);
    int M=SIZE(A);
    while (cin >> N && N > 0) {
        set<vector<int>> Com; int comb=0;
        for (int i=0; i<M; i++) {
            for (int j=0; j<M; j++) {
                for (int k=0; k<M; k++) {
                    vector<int> S;
                    if ((A[i]+A[j]+A[k])==N) { S={A[i], A[j], A[k]}; sort(ALL(S)); Com.insert(S); comb++;}  
                }
            }
        }
        if (comb==0) cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS.\n";
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << N << " IS " << SIZE(Com) << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << N << " IS " << comb << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
