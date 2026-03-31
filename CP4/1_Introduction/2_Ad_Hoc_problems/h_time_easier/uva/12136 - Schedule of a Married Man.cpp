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

int string_to_min(std::string& a) {
    int h = (a[0]-'0')*10 + (a[1]-'0');
    int m = (a[3]-'0')*10 + (a[4]-'0');
    return h*60 + m;
}

void solve(int z) {
    std::string wss, wes, mss, mes; std::cin >> wss >> wes >> mss >> mes;
    int ws = string_to_min(wss), we = string_to_min(wes), ms = string_to_min(mss), me = string_to_min(mes);

    std::cout << "Case " << z << ": " << ((we < ms || ws > me) ? "Hits Meeting" : "Mrs Meeting") << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    int z = 1;
    while (T--) {
        solve(z);
        z++;
    }
    return 0;
}
