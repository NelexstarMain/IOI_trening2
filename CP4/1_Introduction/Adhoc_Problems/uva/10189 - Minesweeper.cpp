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

bool solve(int c) {
    int n, m; std::cin >> n >> m;
    if (n+m == 0) return false;
    if (c > 1) {
        std::cout << "\n";
    }
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                map[i][j] = -1;
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for (int z = 0; z < 8; z++) {
                    if (0 <= dx[z]+i && dx[z]+i < n && 0 <= dy[z]+j && dy[z]+j < m) {
                        if (map[dx[z]+i][dy[z]+j] != -1) {
                            map[dx[z]+i][dy[z]+j]++;
                        }
                    }
                }
            }
        }
    }
    std::cout <<  "Field #" << c << ":\n";
    for (int i = 0; i < n; i++) {
        std::string t = "";
        for (int j = 0; j < m; j++) {
            if (map[i][j] == -1){
                std::cout << '*';
            } else {
                std::cout << std::to_string(map[i][j]);
            }           
        }
        std::cout << "\n";
    }
    return true;
}

int main() {
    fast_io();
    int count = 1;
    while (solve(count)) count++;
    return 0;
}
