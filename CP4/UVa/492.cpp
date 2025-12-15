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

std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

void solve() {
    std::string s; 
    while (getline(std::cin, s)) {
        std::vector<std::string> sv;
        std::stringstream ss(s);
        std::string curr; 
        while (ss >> curr) sv.PB(curr);
        for (auto x: sv) {
            if (std::find(ALL(vowels), x[0]) != vowels.end()) {
                std::cout << x << "yay";
            } else {
                int first = 1;
                while (first < SIZE(x) && (std::find(ALL(vowels), x[first]) == vowels.end())) first++;
                // std::cout << first << "\n" << (first < SIZE(x)) << "\n" << x.substr(first, SIZE(x)-first) << "\n" ;
                std::cout << ((first < SIZE(x)) ? (x.substr(first, SIZE(x)-first)) : "") << x.substr(0, first) << "ay";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
