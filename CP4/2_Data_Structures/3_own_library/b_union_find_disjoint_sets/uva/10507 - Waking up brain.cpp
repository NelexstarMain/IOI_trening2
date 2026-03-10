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

void solve() {
    int s;
    while (cin >> s) {
        int c; cin >> c;
        string a; cin >> a;
        int num = s;
        unordered_set<int> Check;
        for (char x: a) Check.insert(x);
        vector<pair<char, char>> V;
        for (int i=0; i<c; i++) {
            string curr; cin >> curr;
            V.PB({curr[0], curr[1]});
        }
        vector<char> help;
        bool valid = true;
        for (int year = 0; year < 40 && valid == true; year++) {
            int count = 0;
            help.clear();
            for (int n='A'; n<='Z'; n++) {
                if (Check.find(n) != Check.end()) continue;
                int counter = 0;
                for (int j = 0; j < c; j++) {
                    if ((V[j].F == n || V[j].S == n) && (Check.find(V[j].F) != Check.end() || Check.find(V[j].S) != Check.end())) counter++;
                }
                if (counter >= 3) help.PB(n);
            } 
            for (char x: help) Check.insert(x);
            if (SIZE(help) == 0 && SIZE(Check) != num) {
                cout << "THIS BRAIN NEVER WAKES UP\n";
                valid = false;
            } else if (SIZE(help) == 0 && SIZE(Check) == num) {
                cout << "WAKE UP IN, " << year << ", YEARS\n";
                valid = false;
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
