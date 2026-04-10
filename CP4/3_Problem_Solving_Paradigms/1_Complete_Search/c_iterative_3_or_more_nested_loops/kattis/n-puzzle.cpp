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

int diff(string &A, string &B, char C) {
    int F,S;
    for (int i=0; i<SIZE(A); i++) if (A[i]==C) { F=i; break; }
    for (int i=0; i<SIZE(B); i++) if (B[i]==C) { S=i; break; }
    // if ((abs((F/4)-(S/4))+abs((F%4)-(S%4)))!=0) cout << (abs((F/4)-(S/4))+abs((F%4)-(S%4))) << " " << C << "\n";
    return (abs((F/4)-(S/4))+abs((F%4)-(S%4)));
}

void solve() {
    string A="ABCDEFGHIJKLMNO.";
    string B; for (int i=0; i<4; i++) { string C; cin>>C; B+=C; }
    int Dis=0; 
    for (char x: A) if (x!='.') Dis+=diff(A, B, x);
    cout << Dis << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
