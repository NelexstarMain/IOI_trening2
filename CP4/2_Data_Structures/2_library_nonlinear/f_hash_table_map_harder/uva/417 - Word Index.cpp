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

std::unordered_map<std::string, int> A;

void precount() {
    std::vector<std::string> B; 
    std::vector<std::string> C;
    std::vector<std::string> E;
    for (int j = 0; j < 26; j++) { std::string n; n.reserve(5); n = ('a' + j); B.PB(n); E.PB(n); }

    for (int i = 0; i < 4; i++) {
        for (std::string x: B) {
            for (int j = (x.back() - 'a')+1; j < 26; j++) {
                std::string m; m.reserve(5); m += x; m += ('a'+ j);
                C.PB(m);
            }
        }
        B = C;
        for (auto x: C) E.PB(x);
        C.clear();
    }
    std::sort(ALL(E), [](std::string& a, std::string& b) {
        if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);
        return a < b;
    });
    for (int i = 0; i < SIZE(E); i++) A[E[i]] = i+1;
}

void solve() {
    std::string s; 
    precount();
    while (std::cin >> s) {
        if (A.find(s) != A.end()) std::cout << A[s] << "\n";
        else std::cout << "0\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
