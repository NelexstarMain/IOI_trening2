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
    int points = 0;
    int index = 1;
    if (s[0] == 'D' && s[1] == 'D') {
        points++;
        index++;
    } else if (s[0] == 'D') points++;

    for (int i = index; i < s.size(); i++) {
        if (s[i] == 'D') points += 2;
    }
    std::cout << points << "\n";

    points = 0;
    index = 1;
    if (s[0] == 'U' && s[1] == 'U') {
        points++;
        index++;
    } else if (s[0] == 'U') points++;

    for (int i = index; i < s.size(); i++) {
        if (s[i] == 'U') points += 2;
    }
    std::cout << points << "\n";
    points = 0;
    char before = s[0];
    for (int i = 1; i < s.size(); i++) {
        points += (s[i] != before);
        before = s[i];
    } 
    std::cout << points << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
