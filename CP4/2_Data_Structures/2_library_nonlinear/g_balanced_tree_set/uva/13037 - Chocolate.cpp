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

void solve(int z) {
    int l, r, s; std::cin >> l >> r >> s;
    std::unordered_set<int> A, B, C; std::unordered_map<int, int> D;
    for (int i = 0; i < l; i++) { int curr; std::cin >> curr; A.insert(curr); }
    for (int i = 0; i < r; i++) { int curr; std::cin >> curr; B.insert(curr); }
    for (int i = 0; i < s; i++) { int curr; std::cin >> curr; C.insert(curr); }
    for (int x: A) D[x]++; for (int x: B) D[x]++; for (int x: C) D[x]++; 
    int ao = 0, ax = 0, bo = 0, bx = 0, co = 0, cx = 0;
    for (int x: A) if (D[x] == 1) ao++;
    for (int x: B) if (D[x] == 1) bo++;
    for (int x: C) if (D[x] == 1) co++;
    for (auto [k, v]: D) {
        if (v == 2) {
            if (A.find(k) == A.end()) ax++;
            else if (B.find(k) == B.end()) bx++;
            else cx++;
        }
    }
    std::cout << "Case #" << z << ":\n";
    std::cout << ao << " " << ax << "\n" << bo << " " << bx << "\n" << co << " " << cx << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    int z = 1;
    while (T--) solve(z++);
    return 0;
}
