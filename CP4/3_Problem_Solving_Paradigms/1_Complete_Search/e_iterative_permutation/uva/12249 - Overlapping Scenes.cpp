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

int check(vector<string> &A) {
    string W="";
    for (int i=0; i<SIZE(A); i++) {
        string Fi=W, Se=A[i];
        int m=min(SIZE(Fi), SIZE(Se));
        for (int j=m; j>=0; j--) {
            if (Se.substr(0, j)==Fi.substr(SIZE(Fi)-j, j)) {
                W+=Se.substr(j, SIZE(Se)-j);
                break;
            }
        }
    }
    return SIZE(W);
}

void solve(int Z) {
    int N; cin >> N;
    vector<string> A;
    for (int i=0; i<N; i++) {
        string C; cin >> C;
        A.PB(C);
    }
    sort(ALL(A)); 
    int M=INF;   
    do {
        M=min(M,check(A));
    } while (next_permutation(ALL(A)));
    cout << "Case " << Z << ": " << M << "\n";
}

int main() {
    fast_io();
    int T, Z=1; cin >> T;
    while (T--) solve(Z++);
    return 0;
}
