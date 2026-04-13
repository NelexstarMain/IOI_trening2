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

void solve(int z) {
    int S=0;
    cout << "Case " << z << ": ";
    vector<int> A(10); for (int &x: A) { cin >> x; S+=x; };
    int x3=(S/4)-A[0]-A[9];
    if (A[1]==(A[8]-A[9]+A[2])) cout << A[1]-x3 << " " << A[0]-A[1]+x3 << " " << x3 << " " << x3-A[8]+A[9] << " " << A[8]-x3;
    else cout << A[1]-x3 << " " << A[2]-x3 << " " << x3 << " " <<  A[9]-A[8]+x3 << " " << A[8]-x3;
    cout << "\n";
}
int main() {
    fast_io();
    int T; cin >> T;
    int z=1;
    while (T--) solve(z++);
    return 0;
}
