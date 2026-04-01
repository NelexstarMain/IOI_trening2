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

const string S = "0123456789";

vector<string> precompute() {
    vector<string> A = {""}, B;
        for (int i=0; i<5; i++) {
            for (string x: A) {
                for (char y: S) B.PB(x+y);
            }
            A = B; B.clear();
        }
    return A;
}

void solve() {
    int N; 
    vector<string> A = precompute();
    bool first = true;
    while (cin >> N && N > 0) {
        if (!first) cout << "\n";
        first = false;
        bool any = false;
        for (string x: A) {
            int NUM = stoi(x);
            string NEXT = (x+to_string(NUM*N));
            sort(ALL(NEXT));
            if (NEXT == S) { cout << NUM*N << " / " << x << " = " << N << "\n"; any = true; }
        
        }
        if (!any) cout << "There are no solutions for " << N << ".\n";
    }  
}

int main() {
    fast_io();
    solve();
    return 0;
}
