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

struct Quest {
    int id, time, period;
    bool operator<(const Quest& b) const {
        if (time != b.time) return time > b.time;
        else return id > b.id;
    }
};

void solve() {
    std::string s; 
    std::priority_queue<Quest> A;
    while (std::cin >> s && s == "Register") {
        int id, period; std::cin >> id >> period;
        A.push({id, period, period});
    }
    int k; std::cin >> k;
    // std::cout << SIZE(A) << "\n";
    for (int i = 0; i < k; i++) {
        Quest curr = A.top(); A.pop();
        // std::cout << curr.time << "\n";
        std::cout << curr.id << "\n";
        curr.time += curr.period;
        A.push(curr);
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
