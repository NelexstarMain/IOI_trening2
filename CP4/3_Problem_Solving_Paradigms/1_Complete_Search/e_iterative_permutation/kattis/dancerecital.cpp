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

int popcount(int &A) {
    int C=0;
    while (A!=0) {
        A&=(A-1); C++;
    }
    return C;
}


int toint(string &A) {
    int mask=0;
    for (char x: A) mask|=(1<<(x-'A'));
    return mask;
}

int counter(vector<string> &A) {
    int C=0;
    for (int i=1; i<SIZE(A); i++) {
        int add = toint(A[i]) & toint(A[i-1]);
        C+=popcount(add);
    }
    return C;
}

void solve() {
    int N, M=INF; cin >> N;
    vector<string> A(N); for (string &x: A) cin >> x;
    sort(ALL(A));
    do {
        M=min(M, counter(A));
    } while (next_permutation(ALL(A)));
    cout << M << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
