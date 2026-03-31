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


std::vector<std::vector<std::string>> nums = {
    {"***", "* *", "* *", "* *", "***"}, // 0
    {"  *", "  *", "  *", "  *", "  *"}, // 1
    {"***", "  *", "***", "*  ", "***"}, // 2
    {"***", "  *", "***", "  *", "***"}, // 3
    {"* *", "* *", "***", "  *", "  *"}, // 4
    {"***", "*  ", "***", "  *", "***"}, // 5
    {"***", "*  ", "***", "* *", "***"}, // 6
    {"***", "  *", "  *", "  *", "  *"}, // 7
    {"***", "* *", "***", "* *", "***"}, // 8
    {"***", "* *", "***", "  *", "***"}  // 9
};

void solve() {
    std::vector<std::string> all;
    for (int i = 0; i < 5; i++) {
        std::string line;
        std::getline(std::cin, line);
        all.PB(line);
    }
    int size = SIZE(all[0]);
    int index = 0;
    int n = 0;
    while (index < size) {
        std::map<int, int> count;
        bool valid = false;
        for (int i = 0; i < 5; i++) {
            std::string curr = (all[i]).substr(index, 3);
            for (int j = 0; j < 10; j++) {
                if (nums[j][i] == curr) {
                    count[j]++;
                }
            }
        }

        for (auto [x, y]: count) {
                if (y == 5) {
                    n *= 10;
                    n += x;
                    valid = true;
                } 
            }

        if (valid == false) {
            std::cout << "BOOM!!\n";
            return;
        }
        index += 4;
    }

    if (n%6==0) std::cout << "BEER!!\n";
    else std::cout << "BOOM!!\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
