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


std::map<char, std::string> keyMap = {
    {'a', "2"}, {'b', "22"}, {'c', "222"},
    {'d', "3"}, {'e', "33"}, {'f', "333"},
    {'g', "4"}, {'h', "44"}, {'i', "444"},
    {'j', "5"}, {'k', "55"}, {'l', "555"},
    {'m', "6"}, {'n', "66"}, {'o', "666"},
    {'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"},
    {'t', "8"}, {'u', "88"}, {'v', "888"},
    {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"},
    {' ', "0"} 
};


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(int z) {
    std::string s; 
    std::getline(std::cin, s);
    std::string res = "";
    char last = '.';
    for (int i = 0; i < s.size(); i++) {
        std::string news = keyMap[s[i]];
        if (news[0] == last) {
            res += " ";
        }
        res += news;
        last = news[news.size()-1];
    }
    std::cout << "Case #" << z << ": " << res << "\n";
}

int main() {
    fast_io();
    int z = 1;
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) {
        solve(z);
        z++;
    }
    return 0;
}
