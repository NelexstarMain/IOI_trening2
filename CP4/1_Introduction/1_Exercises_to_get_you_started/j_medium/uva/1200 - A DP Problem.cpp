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

int parse_coeff(string s) {
    // Usuwamy 'x' z końca
    string num = s.substr(0, SIZE(s) - 1);
    
    if (num == "" || num == "+") return 1;  
    if (num == "-") return -1;             
    
    return std::stoi(num);                 
}

void solve() {
    std::string s; std::cin >> s;
    bool left = true;
    int lx = 0, ln = 0, rx = 0, rn = 0;
    std::vector<std::string> leftv, rightv;
    int start = 0;  
    for (int i = 0; i < SIZE(s); i++) {
        if (i!=start && (s[i]=='+'||s[i]=='-')) {
            if (left) {
                leftv.PB(s.substr(start, i-start));
            } else {
                rightv.PB(s.substr(start, i-start));
            }
            start=i;
            
        }
        if (i==(SIZE(s)-1)) {
            rightv.PB(s.substr(start, i+1-start));
        }
        if (s[i]=='=') {
            leftv.PB(s.substr(start, i-start));
            left = false;
            start=i+1;
        }
        
    }
    for (auto& x : leftv) {
        if (x.empty()) continue;
        if (x.back() == 'x') lx += parse_coeff(x);
        else ln += std::stoi(x);
    }
    for (auto& x : rightv) {
        if (x.empty()) continue;
        if (x.back() == 'x') rx += parse_coeff(x);
        else rn += std::stoi(x);
    }
    if (lx==rx && ln==rn) std::cout << "IDENTITY\n";
    else if (lx==rx && ln!=rn) std::cout << "IMPOSSIBLE\n";
    else {
        lx -= rx;
        rn -= ln;
        std::cout << (long long)std::floor((double)rn / lx) << "\n";
    }
        
}


int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
