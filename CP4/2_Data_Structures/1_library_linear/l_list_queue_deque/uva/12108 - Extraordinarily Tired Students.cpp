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

struct Student {
    int a, b, c;
    int nextchange;
    bool is_sleeping;

    Student(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {
        if (c > a) { is_sleeping = true; nextchange = ((a+b)-c) }
        else { is_sleeping = false; nextchange = (a-c) }
    }
    bool check(int t, int n, int sleeping) {  // true = sleeping
        if (t > nextchange && (sleeping+1 >= (int)((n+1))/2)) { is_sleeping = true; nextchange += b; return true;}
        else return false;
    }
}



void solve() {
    int n; 
    while (std::cin >> n && n > 0) {
        std::vector<Student> A; 
        for (int i = 0; i < n; i++) {
            int a, b, c; std::cin >> a >> b >> c;
            Student(a, b, c);
        }   
    }
    for (int t = 1; t < 10e5; t++) {
        
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
