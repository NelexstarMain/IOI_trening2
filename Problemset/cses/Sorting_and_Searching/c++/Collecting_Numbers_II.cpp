#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), pos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int all = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i+1]) all++;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << all << "\n";
            continue;
        }

        int v1 = a[x], v2 = a[y];
        vector<pair<int,int>> check;

        auto add = [&](int u, int v) {
            if (u >= 1 && v >= 1 && u <= n && v <= n) {
                check.push_back({u, v});
            }
        };

        // dodajemy pary do sprawdzenia
        add(v1-1, v1);
        add(v1, v1+1);
        add(v2-1, v2);
        add(v2, v2+1);

        // unikamy duplikatów
        sort(check.begin(), check.end());
        check.erase(unique(check.begin(), check.end()), check.end());

        // odejmujemy stare naruszenia
        for (auto [u, v] : check) {
            if (pos[u] > pos[v]) all--;
        }

        // swap
        swap(a[x], a[y]);
        pos[v1] = y;
        pos[v2] = x;

        // dodajemy nowe naruszenia
        for (auto [u, v] : check) {
            if (pos[u] > pos[v]) all++;
        }

        cout << all << "\n";
    }
}

int main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
