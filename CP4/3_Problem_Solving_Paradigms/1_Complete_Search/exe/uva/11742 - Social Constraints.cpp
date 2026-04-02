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
        vector<vector<int>> min_dist(N, vector<int>(N, 1));
        vector<vector<int>> max_dist(N, vector<int>(N, N + 1));

        for (int i = 0; i < M; i++) {
            int A, B, C; 
            cin >> A >> B >> C;
            if (C > 0) max_dist[A][B] = max_dist[B][A] = min(max_dist[A][B], C);
            else if (C < 0) min_dist[A][B] = min_dist[B][A] = max(min_dist[A][B], -C);
        }

        vector<int> V; 
        for (int i = 0; i < N; i++) V.PB(i);
        
        int count = 0;
        do {
            bool valid = true;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    int a = V[i], b = V[j];
                    int dist = abs(j - i); 
                    if (dist < min_dist[a][b] || dist > max_dist[a][b]) {
                        valid = false;
                        break; 
                    }
                }
                if (!valid) break; 
            }
            if (valid) count++;
        } while (next_permutation(ALL(V)));
        cout << count << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}