#include <bits/stdc++.h>;

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

std::string sumu(std::string f, std::string s) {
    reverse(ALL(f)); 
    reverse(ALL(s));

    int n = SIZE(f), m = SIZE(s);
    int max_len = max(n, m);
    vector<int> r(max_len + 1, 0);

    for (int i = 0; i < max_len; i++) {
        int a = (i < n) ? f[i] - '0' : 0;
        int b = (i < m) ? s[i] - '0' : 0;
        
        int sum = a + b + r[i];
        r[i] = sum % 10;      
        r[i+1] = sum / 10;   
    }

    while (SIZE(r) > 1 && r.back() == 0) r.pop_back();
    reverse(ALL(r));
    std::string res = "";
    for (int x : r) res += (char)(x + '0');
    return res;
}

std::string devide(std::string a, int b) {
    std::string res = "";
    int re = 0;
    for (char x : a) {
        int curr = re * 10 + (x - '0');
        int ma = curr / b;
        re = curr % b;
        if (ma || !res.empty()) {
            res += std::to_string(ma);
        }
    }
    return res.empty() ? "0" : res; 
}

void solve() {
    int n, m;
    int bill = 1;
    while (std::cin >> n >> m && n > 0) {
        std::string res = "0";
        for (int i = 0; i < n; i++) {
            std::string curr; std::cin >> curr;
            res = sumu(res, curr);
        }   
        std::cout << "Bill #" << bill << " costs " << res << ": each friend should pay " << devide(res, m) << "\n\n";
        bill++;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
