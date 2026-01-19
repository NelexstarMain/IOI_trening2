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
// 1
// zadanie gracz czas 
// 1 2 10 I
// 3 1 11 C
// 1 2 19 R
// 1 2 21 C
// 1 1 25 C
std::string l;
void solve() {
    std::map<int, std::pair<int, int>> teams;
    std::set<int> teamsName;
    std::vector<int> teamsNames;
    std::map<int, std::map<int, int>> a;
    std::map<int, std::map<int, bool>> b{};
    while (std::getline(std::cin, l) && !l.empty()) {
        std::stringstream ss(l);
        int e, p, t; ss >> p >> e >> t;
        char s; ss >> s;
        if (b[p][e]) continue;
        if (s == 'C') {
            teams[p].F++;
            teams[p].S += t + a[p][e];
            b[p][e] = true;

        } else if (s == 'I') {
            a[p][e] += 20;
        }
        teamsName.insert(p);
    }
    for (int x: teamsName) teamsNames.PB(x);
    std::sort(ALL(teamsNames), [&teams](int& a, int& b) {
        if (teams[a].F != teams[b].F) return teams[a].F > teams[b].F;
        else if (teams[a].S != teams[b].S) return teams[a].S < teams[b].S;
        else return a < b;
    });
    for (int i = 0; i < SIZE(teamsNames); i++) {
        int x = teamsNames[i];
        std::cout << x << " " << teams[x].F << " " << teams[x].S << "\n";
    }

}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    std::getline(std::cin, l);
    while (T--) {
        solve();
        if (T > 0) std::cout << "\n";
    }
    return 0;
}
