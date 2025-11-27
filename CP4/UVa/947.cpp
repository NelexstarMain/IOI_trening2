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
    std::string s; std::cin >> s;
    std::unordered_map<int, int> awjf;
    for (char x: s) awjf[x]++;
    int x, y; std::cin >> x >> y;
    std::vector<std::string> permutaions = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (int i = 1; i < s.size(); i++) {
        std::vector<std::string> per = permutaions;
        permutaions.clear();
        for (int j = 1; j <= 9; j++) {
            for (auto x: per) {
                permutaions.push_back(x+std::to_string(j));
            }
        }
    }

   ll count = 0;

    for (auto &secret_code : permutaions) {
        int a = 0; 
        int guess_counts[10] = {0};
        int secret_counts[10] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (secret_code[i] == s[i]) {
                a++;
            } else {
                int guess_digit = s[i] - '0';
                int secret_digit = secret_code[i] - '0';
                
                guess_counts[guess_digit]++;
                secret_counts[secret_digit]++;
            }
        }

        int b = 0;
        for (int c = 1; c <= 9; ++c) {
            b += min(guess_counts[c], secret_counts[c]);
        }

        if (a == x && b == y) {
            count++;
        }
    }

    cout << count << "\n";
    
}   

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
