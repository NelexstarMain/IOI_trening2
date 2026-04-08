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

std::vector<std::vector<int>> row(int a, int b, std::vector<std::vector<int>>& v) {
    a--; b--;
    std::vector<int> f = v[a], s = v[b];
    v[b] = f; v[a] = s;
    return v;
}

std::vector<std::vector<int>> col(int a, int b, std::vector<std::vector<int>>& v) {
    a--; b--;
    for (int i = 0; i < SIZE(v); i++) {
        int f = v[i][a], s = v[i][b];
        v[i][b] = f; v[i][a] = s;
    }
    return v;
}

std::vector<std::vector<int>> inc(std::vector<std::vector<int>>& v) {
    for (int i = 0; i < SIZE(v); i++) {
        for (int j = 0; j < SIZE(v[0]); j++) {
            v[i][j] = (v[i][j]+1)%10;
        }
    }
    return v;
}

std::vector<std::vector<int>> dec(std::vector<std::vector<int>>& v) {
    for (int i = 0; i < SIZE(v); i++) {
        for (int j = 0; j < SIZE(v[0]); j++) {
            v[i][j] = (v[i][j]+9)%10;
        }
    }
    return v;
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& v) {
    int x = SIZE(v[0]), y = SIZE(v);
    std::vector<std::vector<int>> newv(x, std::vector<int>(y, 0));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            newv[i][j] = v[j][i];
        }
    }
    return newv;
}

void solve(int z) {
    int n; 
    if (!(std::cin >> n)) return;
    
    vector<vector<int>> cur(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s; 
        for (int j = 0; j < n; j++) {
            cur[i][j] = s[j] - '0';
        }
    }

    int ac; std::cin >> ac;
    while (ac--) {
        std::string s; std::cin >> s;
        if (s == "transpose") {
            cur = transpose(cur);
        } else if (s == "row") {
            int a, b; std::cin >> a >> b;
            cur = row(a, b, cur);
        } else if (s == "col") {
            int a, b; std::cin >> a >> b;
            cur = col(a, b, cur);
        } else if (s == "inc") {
            cur = inc(cur);
        } else if (s == "dec") {
            cur = dec(cur);
        }
    }

    std::cout << "Case #" << z << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << cur[i][j];
        }
        std::cout << "\n"; 
    }
    std::cout << "\n"; 
}

int main() {
    fast_io();
    int T; 
    if (!(std::cin >> T)) return 0;
    int z = 1;
    while (T--) {
        solve(z);
        z++;
    }
    return 0;
}
