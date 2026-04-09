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

bool check(string &A, string &B) {
    for (int i=0; i<SIZE(A); i++) if (A[i]=='2' && B[i]=='2') return false;
    return true;
}

void solve() {
    string A, B; 
    while (cin >> A >> B) {
        int M = INF, N = SIZE(A), Nk = SIZE(B);
        int sg = -Nk;
        string C(100, '1'); B+=C;
        string D(SIZE(A), '1');
        for (int i=0; i<(N+Nk); i++) {
            int start = min(0, sg);
            int end = max(N, sg+Nk);
            if (check(A, D)) M=min(M, end-start);
            sg++; D = D.substr(1) + B[0];
            B.erase(0, 1);
        }
        cout << M << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
