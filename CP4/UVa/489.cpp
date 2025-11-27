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

bool solve() {
    int n; std::cin >> n;
    if (n == -1) return false;
    std::string s, t; std::cin >> s >> t;
    int ss = s.size(), ts = t.size();
    int wrong = 0, good = 0;
    std::cout << "Round " << n << "\n";
    std::unordered_map<char, int> word;
    for (char x: s) word[x]++;
    for (int i = 0; i < ts; i++) {
        if (word.find(t[i]) != word.end()) {
            if (word[t[i]] > 0) {
                good += word[t[i]];
                word[t[i]] = 0;
            }
        } else {
            wrong++; 
        }
        if (wrong >= 7) {
            std::cout << "You lose.\n";
            return true;
        } else if (good == ss) {
            std::cout << "You win.\n";
            return true;
        }
    }

    if (good < ss) std::cout << "You chickened out.\n";
        
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}
