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

std::unordered_map<char, int> charToDigit = {
    {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1},
    {'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2},
    {'D', 3}, {'T', 3},
    {'L', 4},
    {'M', 5}, {'N', 5},
    {'R', 6}
};

// void solve() {
//     std::string s;
//     while (std::cin >> s) {
//         std::string res = "";
//         for (int i = 0; i < SIZE(s); i++) {
//             int j = i+1;
//             while (j < SIZE(s) && s[j] == s[i]) j++;
//             i = j-1;
//             char x = s[i];
//             if (charToDigit[x] > 0) {
//                 res += (char)(charToDigit[x]+'0');
//             }
//         }
//         std::cout << res << "\n";
//     }
// }

void solve() {
    std::string s;
    while (std::cin >> s) {
        std::string res = "";
        int lastDigit = -1; 

        for (char c : s) {
            if (charToDigit.count(c)) {
                int currentDigit = charToDigit[c];
                if (currentDigit != lastDigit) {
                    res += (char)(currentDigit + '0');
                }
                lastDigit = currentDigit; 
            } else {
                lastDigit = -1; 
            }
        }
        std::cout << res << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
