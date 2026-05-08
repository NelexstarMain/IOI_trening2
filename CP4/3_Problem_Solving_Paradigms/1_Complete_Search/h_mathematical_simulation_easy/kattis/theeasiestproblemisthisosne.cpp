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

int count(int X) {
    string x=to_string(X); int C=0;
    for (char y: x) C+=(y-'0');
    return C;
} 

void solve() {
    int N;
    while (cin >> N && N > 0) {
        int R=count(N);
        for (int i=11; i<=100; i++) {
            if (count(N*i)==R) {
                cout << i << "\n";
                break;
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
