#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;

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

const int Mon[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vs exract(string &A) {
    return {A.substr(0,2), A.substr(2, 2), A.substr(4, 4)};
}

int leapyear(int &Y, int &M) {
    if (((Y%400==0) || (Y%4==0 && Y%100!=0)) && M==2) return 29;
    else return Mon[M]; 
}

bool check(string &A) {
    vs B = exract(A);
    int day=stoi(B[0]), mon=stoi(B[1]), year=stoi(B[2]);
    if ((0<mon&&mon<13) && (0<day&&day<=leapyear(year, mon)) && (year>=2000)) return true;
    else return false;
}

void solve() {
    string H=""; 

    for (int i=0; i<3; i++) {
        string C; cin >> C; H+=C;
    }   

    vector<vs> Correct; 
    sort(ALL(H));
    
    do {
        if (check(H)) Correct.PB(exract(H));
    } while (next_permutation(ALL(H)));

    sort(ALL(Correct), [](vs &x, vs &y) {
        if (x[2]!=y[2]) return x[2]<y[2];
        else if (x[1]!=y[1]) return x[1]<y[1];
        else return x[0]<y[0];
    });
    
    cout << SIZE(Correct);
    
    if (SIZE(Correct)>0) {
        vs R=Correct[0];
        cout << " " << R[0] << " " << R[1] << " " << R[2];
    }

    cout << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
