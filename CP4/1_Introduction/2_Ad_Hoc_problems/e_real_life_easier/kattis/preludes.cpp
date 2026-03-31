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

std::unordered_map<std::string, std::string> change = {{"A#", "Bb"}, {"C#", "Db"}, {"D#", "Eb"}, {"F#", "Gb"}, {"G#", "Ab"}, 
                                                {"Bb", "A#"}, {"Db", "C#"},  {"Eb", "D#"},  {"Gb", "F#"}, {"Ab", "G#"}};

bool solve(int t) {
    std::string f, s;
    if (!(std::cin >> f >> s)) return false;
    else {
        if (change.find(f) != change.end()) {
            f = change[f];
            std::cout << "Case " << t << ": " << f << " " << s << "\n";
        } else {
            std::cout << "Case " << t << ": " << "UNIQUE\n";
        }
        
    }
    return true;
}

int main() {
    fast_io();
    int t = 1;
    while (solve(t)) t++;
    return 0;
}
