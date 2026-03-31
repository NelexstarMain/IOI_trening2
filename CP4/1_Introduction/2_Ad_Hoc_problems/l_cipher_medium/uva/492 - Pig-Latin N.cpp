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
        std::string current_word = "";
        std::string punctuation_suffix = "";
        
        for (char c : s) {
            if (std::isalpha(c)) {
                if (!punctuation_suffix.empty()) {
                    if (!current_word.empty() && std::find(ALL(vowels), current_word[0]) == vowels.end()) {
                        std::cout << current_word.substr(1) << current_word[0] << "ay";
                    } 
                    else if (!current_word.empty()) {
                        std::cout << current_word << "ay";
                    }

                    std::cout << punctuation_suffix;
                    current_word = "";
                    punctuation_suffix = "";
                }
                current_word += c;
                
            } else {
                if (!current_word.empty() && punctuation_suffix.empty()) {
                    punctuation_suffix += c;
                } 
                else if (!current_word.empty()) {
                    punctuation_suffix += c;
                }
                else {
                    std::cout << c;
                }
            }
        }
        if (!current_word.empty()) {
            if (std::find(ALL(vowels), current_word[0]) != vowels.end()) {
                std::cout << current_word << "ay"; 
            } else {
                std::cout << current_word.substr(1) << current_word[0] << "ay"; 
            }
        }
        std::cout << punctuation_suffix;
        std::cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}