#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mss = map<string, string>;


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
// {xyz:123456789123456789123456789,x:1}
mss change(string A) {
    mss B;
    if (A == "{}" || A.size() <= 2) return B;
    string name = "", value = "";
    for (int i = 1; i < (int)A.size(); i++) {
        char c = A[i];
        if (isalpha(c)) name += c;
        else if (isdigit(c)) value += c;
        else if (c == ',' || c == '}') {
            if (!name.empty()) B[name] = value;
            name = ""; value = "";
        }
    }
    return B;
}

void print_line(char x, std::vector<std::string> T) {
    if (SIZE(T) > 0) {
        std::cout << "+"; 
        for (int i = 0; i < SIZE(T); i++) std::cout << T[i] << ((i < SIZE(T)-1)?",":"");
        std::cout << "\n";
    }
}

void solve() {
    std::string l; 
    std::getline(std::cin, l); mss O = change(l);
    std::getline(std::cin, l); mss N = change(l);

    std::vector<std::string> K; for (auto [k, v]: N) if (O.find(k) == O.end()) K.PB(k);
    std::vector<std::string> KD; for (auto [k, v]: O) if (N.find(k) == N.end()) KD.PB(k);
    std::vector<std::string> CH; for (auto [k, v]: O) if (N.find(k) != N.end() && N[k] != v) CH.PB(k);

    print_line('+', K);
    print_line('-', KD);
    print_line('*', CH);
    
    if (SIZE(K) == 0 && SIZE(KD) == 0 && SIZE(CH) == 0) std::cout << "No changes\n"; 
    std::cout << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) solve();
    return 0;
}
