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

struct Drug {
    int priority, time, period; std::string name;
    bool operator<(const Drug& b) const {
        if (time != b.time) return time > b.time;
        else return priority > b.priority;
    }
};

void solve() {
    std::string s; 
    std::priority_queue<Drug> A;
    int n, k; std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::string name; std::cin >> name;
        int p; std::cin >> p;
        A.push({i, p, p, name});
    }

    for (int i = 0; i < k; i++) {
        Drug curr = A.top(); A.pop();
        std::cout << curr.time << " " << curr.name << "\n";
        curr.time += curr.period;
        A.push(curr);
    }
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
