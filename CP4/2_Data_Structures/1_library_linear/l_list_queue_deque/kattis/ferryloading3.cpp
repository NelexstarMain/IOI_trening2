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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, travel_t, m; 
    if (!(cin >> n >> travel_t >> m)) return;
    
    deque<pii> L, R;
    FWD(i, 0, m) {
        int arrival; string side;
        cin >> arrival >> side;
        if (side == "left") L.push_back({arrival, i});
        else R.push_back({arrival, i});
    }

    vector<int> res(m);
    int t = 0;
    bool left = true;

    while (!L.empty() || !R.empty()) {
        int next_L = L.empty() ? INF : L.front().F;
        int next_R = R.empty() ? INF : R.front().F;
        int earliest = min(next_L, next_R);

        t = max(t, earliest);

        bool has_L = !L.empty() && L.front().F <= t;
        bool has_R = !R.empty() && R.front().F <= t;
        if (left) {
            if (has_L || has_R) { 
                int count = 0;
                while (!L.empty() && L.front().F <= t && count < n) {
                    res[L.front().S] = t + travel_t;
                    L.pop_front();
                    count++;
                }
                t += travel_t;
                left = false;
            }
        } else {
            if (has_R || has_L) {
                int count = 0;
                while (!R.empty() && R.front().F <= t && count < n) {
                    res[R.front().S] = t + travel_t;
                    R.pop_front();
                    count++;
                }
                t += travel_t;
                left = true;
            }
        }
    }

    FWD(i, 0, m) cout << res[i] << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    FWD(i, 0, T) {
        solve();
        if (i < T - 1) cout << "\n";
    }
    return 0;
}