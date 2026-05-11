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
    while (cin >> N && N >= 0) { 
        cout << N << " coconuts, ";
        bool found = false;
        for (int n = sqrt(N) + 1; n >= 2; n--) {
            int current = N;
            bool possible = true;
            for (int j = 0; j < n; j++) {
                if (current % n != 1) {
                    possible = false;
                    break;
                }
                current -= (1 + (current - 1) / n);
            }
            if (possible && current % n == 0) {
                cout << n << " people and 1 monkey\n";
                found = true;
                break; 
            }
        }

        if (!found) {
            cout << "no solution\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
