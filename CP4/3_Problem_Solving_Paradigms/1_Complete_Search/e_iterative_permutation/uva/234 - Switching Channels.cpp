#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>; 

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

vector<vi> C(5);

vi check(vi &A) {
    vi S={0}; int N=0;
    for (int i=0; i<SIZE(A); i++) {
        N+=A[i]; S.PB(N);
    }
    vi Res(5, 0);
    for (int i=0; i<5; i++) {
        for (int x: C[i]) {
            int M=INF;
            for (int y: S) M=min(M, abs(x-y));
            Res[i]+=M;
        }
    }
    return Res;
}

void solve() {
    int N; 
    while (cin >> N && N > 0) {
        vi A(N); for (int &x: A) cin >> x;
        int P; cin >> P;
        for (int i=0; i<P; i++) {
            int p, time; cin >> p >> time; 
            C[p-1].PB(time);
        }
        sort(ALL(A));
        vi Res={INF, INF, INF, INF, INF};
        vi Best;
        do {
            vi An=check(A);
            if (An<Res) {
                Res=An;
                Best=A;
            }
        } while (next_permutation(ALL(A)));
        cout << "Data set " << Z << "\n";
        cout << "   Order:";
        for (int x: Best) cout << " " << x;
        cout << "\n" << "   Error: " << (Res[0]+Res[1]+Res[2]+Res[3]+Res[4]) << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
