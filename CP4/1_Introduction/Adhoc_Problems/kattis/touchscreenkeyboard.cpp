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

std::unordered_map<char, pii> chars;


void solve() {
    std::string start; std::cin >> start;
    int count; std::cin >> count;
    std::vector<std::string> all;
    std::unordered_map<std::string, int> distances;
    for (int i = 0; i < count; i++) {
        std::string curr; std::cin >> curr;
        int dis = 0;
        for (int j = 0; j < curr.size(); j++) {
            pii first = chars[curr[j]];
            pii second = chars[start[j]];
            dis += std::abs(first.first-second.first) + std::abs(first.second-second.second);
        }
        all.PB(curr);
        distances[curr] = dis;
    }
    std::sort(ALL(all), [&distances](std::string& a, std::string& b) {
        if (distances[a] != distances[b]) return distances[a] < distances[b];
        return a < b;
    });
    for (auto x: all) {
        std::cout << x << " " << distances[x] << "\n";
    }
}

int main() {

    std::vector<std::string> keyboard = {
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < keyboard[i].size(); j++) {
            chars[keyboard[i][j]] = {i, j};
        }
    }

    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
