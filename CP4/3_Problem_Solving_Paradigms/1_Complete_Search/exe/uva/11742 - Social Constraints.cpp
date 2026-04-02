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
    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<vector<int>> AM(N, vector<int>(N, 0));
        for (int i=0; i<M; i++) {
            int A, B, C; cin >> A >> B >> C;
            AM[A][B] = AM[B][A] = C;
        }
        vector<int> V; for (int i=0; i<N; i++) V.PB(i);
        int count = 0;
        do {
            // for (int x: V) cout << x << " ";
            // cout << "\n";
            bool valid = true;
            for (int i=0; i<N; i++) {
                for (int j=i+1; j<N; j++) {
                    if (i==j) continue;
                    int a = V[i], b = V[j];
                    if (AM[a][b] != 0) {
                        if (AM[a][b] < 0 && abs(j-i) < abs(AM[a][b])) valid = false;
                        if (AM[a][b] > 0 && abs(j-i) > abs(AM[a][b])) valid = false;
                    }
                }
            }
            if (valid) count++;
            // cout << count << "\n";
        } while (next_permutation(ALL(V)));
        cout << count << "\n";
    }

}

int main() {
    fast_io();
    solve();
    return 0;
}
