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
    while (std::getline(std::cin, l)) {
        if (l.empty()) continue;
        
        std::stringstream ss(l);
        std::stack<int> a;  
        std::stack<int> su; 
        su.push(0);
        
        bool valid = true;
        int c;
        
        while (ss >> c) {
            if (c < 0) {
                a.push(c); 
                su.push(0);
            } else {
                if (a.empty() || a.top() != -c) {
                    valid = false;
                    break;
                }
                
                int current_inner_sum = su.top();
                su.pop();
                a.pop();

                if (current_inner_sum >= c) {
                    valid = false;
                    break;
                }
                if (!su.empty()) {
                    su.top() += c; 
                }
            }
        }

        if (valid && a.empty()) {
            std::cout << ":-) Matrioshka!\n"; 
        } else {
            std::cout << ":-( Try again.\n"; 
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}