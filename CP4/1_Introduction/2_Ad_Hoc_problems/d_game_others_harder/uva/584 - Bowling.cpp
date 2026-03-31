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

int check(char a) {
    if (a == 'X' || a == '/') {
        return 10;
    } else if (a == '-') {
        return 0;
    } else {
        return a - '0';
    }
}

bool solve() {
    int score = 0;
    std::string s;
    
    if (!std::getline(std::cin, s) || s.empty()) return false;
    
    stringstream ss(s);
    std::vector<char> points;
    std::string token;
    
    stringstream clean_ss(s);
    while (clean_ss >> token) {
         if (token == "Game") return false;
         if (token.length() == 1) {
             points.push_back(token[0]);
         }
    }
    
    if (points.empty()) return false;

    int index = 0;
    for (int i = 0; i < 10; i++) {
        if (index >= SIZE(points)) break;
        
        char curr = points[index];
        if (curr == 'X') {
            if (index + 2 < SIZE(points) && points[index+2] == '/') {
                score += 20;
            } else if (index + 2 < SIZE(points)) {
                score += check(points[index+1]) + check(points[index+2]) + 10;
            } else if (index + 1 < SIZE(points)) {
                score += check(points[index+1]) + 10;
            } else {
                score += 10;
            }
            index++;
            continue;
        } else if (index + 1 < SIZE(points) && points[index+1] == '/') {
            if (index + 2 < SIZE(points)) {
                score += check(points[index+2]) + 10;
            } else {
                score += 10;
            }
            index += 2;
        } else {
            if (index + 1 < SIZE(points)) {
                score += check(points[index]) + check(points[index+1]);
            } else {
                score += check(points[index]);
            }
            index += 2;
        }
    }
    std::cout << score << "\n";
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}