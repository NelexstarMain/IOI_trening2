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

bool solve(int z) {
    int n, c; std::cin >> n >> c;
    if (n == 0 && c == 0) return false;
    std::unordered_map<std::string, int> values;
    std::vector<std::string> words;
    int max_value = -1;
    for (int i = 0; i < c; i++) {
        std::string s; std::cin >> s;
        int count; std::cin >> count;
        if (count >= 5) {
            max_value = std::max(max_value, count);
            values[s] = count;
            words.PB(s);
        }
        
    }
    int height = 0, max_height = 0;
    int used = n+10;
    std::sort(ALL(words));
    for (int i = 0; i < words.size(); i++) {
        int P = 8 + std::ceil((40.0*(values[words[i]]-4))/(max_value-4));
        std::string word = words[i];
        int size = word.size();
        int width = std::ceil(9.0/16*size*P)+10;
        if (used - width >= 0) {
            used -= width;
            max_height = std::max(max_height, P);
        } else {
            height += max_height;
            max_height = P;
            used = n+10-width;
        }
        
    }
    height += max_height;
    std::cout << "CLOUD " << z << ": " << height << "\n";
    return true;

}
int main() {
    fast_io();
    int z = 1;
    while (solve(z)) z++;
    return 0;
}
