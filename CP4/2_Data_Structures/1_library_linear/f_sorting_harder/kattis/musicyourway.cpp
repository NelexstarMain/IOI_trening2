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

// Artist Album Song_Title Length_seconds
// 5
// Tchaikovsky Piano_Favorites November 163
// James_Taylor Dad_Loves_His_Work Hard_Times 192
// James_Taylor Dad_Loves_His_Work London_Town 236
// James_Taylor Dad_Loves_His_Work Summers_Here 163
// George_Winston Summer Lullaby 215
// 3
// Artist
// Album
// Song_Title

void solve() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num = 0;
    std::string curr;
    std::map<std::string, int> h;
    std::vector<std::string> g;
    while (ss >> curr) {
        h.insert({curr, num});
        g.PB(curr);
        num++;
    }
    int n; std::cin >> n;

    std::vector<std::vector<std::string>> a(n, std::vector<std::string>(num));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < num; j++) {
            std::string now; std::cin >> now;
            a[i][j] = now;
        }
    }
    // std::vector<std::string> sorts;
    int k; std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::string sorter; std::cin >> sorter;
        // sorts.PB(sorter);
        // std::sort(ALL(a), [&sorts, &h](std::vector<std::string>& a, std::vector<std::string>& b) {
        //     for (std::string type: sorts) {
        //         int v = h[type];
        //         if (a[v] != b[v]) return a[v] < b[v];
        //         else continue;
        //     }
        // });
        int index = h[sorter];
        std::stable_sort(ALL(a), [&index](const std::vector<std::string>& a, const std::vector<std::string>& b) {
            return a[index] < b[index];
        });
        for (auto x: g) std::cout << x << " ";
        std::cout << "\n";
        for (int j = 0; j < n; j++) {
            std::string l = "";
            for (int z = 0; z < num; z++) {
                l += a[j][z] + ((z!=num-1)?" ":"");
            }
            std::cout << l << "\n";
        }
        if (i < k-1) std::cout << "\n";
        
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
