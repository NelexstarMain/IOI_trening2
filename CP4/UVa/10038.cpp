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
    std::string line; 
    while (getline(std::cin, line) && !line.empty()) {
        std::vector<int> ch(3005, 0);
        std::stringstream ss(line);
        int b; ss >> b;
        ss >> b;
        int co = 1;
        int c; 
        while (ss >> c) {
            ch[std::abs(c-b)]++;
            b = c;
            co++;
        } 
        bool valid = true;
        // for (int i = 0; i < 10; i++) std::cout << ch[i] << " ";
        for (int i = 1; i < co; i++) {
            if (ch[i] != 1) {
                if (valid) std::cout << "Not jolly\n";
                valid = false;
            } 
        }
        if (valid) std::cout << "Jolly\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
