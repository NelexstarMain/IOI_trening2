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
    std::string l; 
    std::getline(std::cin >> std::ws, l);
    if (!l.empty() && l.back() == '\r') l.pop_back();

    for (char &c: l) c = std::toupper(c); 
    std::cout << l << "\n";
    
    std::map<std::string, int> A;
    int m, n, b; 
    std::cin >> m >> n >> b;
    for (int i = 0; i < m; i++) {
        std::string name; int cost; 
        std::cin >> name >> cost;
        A[name] = cost;
    }
    
    std::vector<std::pair<std::string, int>> C;
    for (int i = 0; i < n; i++) {
        int cost = 0;
        
        std::getline(std::cin >> std::ws, l);
        if (!l.empty() && l.back() == '\r') l.pop_back();
        
        int ing; std::cin >> ing;
        for (int j = 0; j < ing; j++) {
            std::string curr; int quant; std::cin >> curr >> quant;
            cost += (A[curr] * quant);
        }
        if (cost <= b) C.PB({l, cost});
    }
    
    std::sort(ALL(C), [](std::pair<std::string, int>& x, std::pair<std::string, int>& y){
        if (x.S != y.S) return x.S < y.S;
        return x.F < y.F; 
    });
    
    if (SIZE(C) > 0) {
        for (auto [k, v]: C) std::cout << k << "\n";
    } else {
        std::cout << "Too expensive!\n";
    }
    
    std::cout << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}