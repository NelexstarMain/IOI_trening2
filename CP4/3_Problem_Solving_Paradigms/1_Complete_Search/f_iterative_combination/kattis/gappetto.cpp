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

vector<int> Mask;

bool check(int A) {
    for (int x: Mask) {
        if ((A&&x)==x) return false;
    }
    return true;
}

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        int mask=0; a--; b--;
        mask+=((1<<a)+(1<<b));
        Mask.PB(mask);
    }
    int Nu=(1<<N), Co=0;
    for (int i=0; i<=Nu; i++) {
        if (check(i)) Co++;
    }    
    cout << Co << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
