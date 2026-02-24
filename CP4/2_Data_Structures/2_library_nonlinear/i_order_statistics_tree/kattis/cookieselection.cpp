#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;



void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    std::string s; 
    ordered_set A; int global = 0;
    while (std::cin >> s) {
        if (s == "#") { auto it = A.find_by_order(SIZE(A)/2); std::cout << it->F << "\n"; A.erase(it); }
        else { int c = std::stoi(s); A.insert({c, global++}); }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
