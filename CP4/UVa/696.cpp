// #include <bits/stdc++.h>

// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define REP(i, a, b) for(int i = a; i <= b; ++i)
// #define FWD(i, a, b) for(int i = a; i < b; ++i)
// #define REV(i, a, b) for(int i = a; i >= b; --i)
// #define ALL(a) (a).begin(), (a).end()
// #define SIZE(a) (int)((a).size())

// const int INF = 1e9 + 7;
// const ll LINF = 1e18 + 7;
// const int MOD = 1e9 + 7;

// void fast_io() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }

// bool solve() {
//     int x, y; std::cin >> x >> y;
//     if (x+y==0) {
//         return false;
//     }
//     int second = 0;
//     std::vector<std::vector<bool>> map(x, std::vector<bool>(y, true));
//     int n_dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
//     int n_dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             if (map[i][j] == true) { 
//                 second++;
//                 for (int z = 0; z < 8; z++) {
//                     int next_i = i + n_dx[z];
//                     int next_j = j + n_dy[z];
//                     if (0 <= next_i && next_i < x && 0 <= next_j && next_j < y) {
//                         map[next_i][next_j] = false;
//                     }
//                 }
//             }
//         }
//     }
//     int first = (x*y+1)/2;
//     std::cout << std::max(first, second) << " knights may be placed on a " << x << " row " << y << " column board.\n";
//     return true;

// }
// int main() {
//     fast_io();
//     while (solve());
//     return 0;
// }
#include <bits/stdc++.h>  

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

ll MOD = 998244353;
double eps = 1e-12;
const int INF = 1e9;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    while(cin >> m >> n) {
        if(!m && !n) break;

        int mi, ma, res;
        mi = min(m, n);
        ma = max(m, n);

        if(mi == 1) res = ma;

        else res = (ma * mi + 1) / 2;
        cout << res << " knights may be placed on a " << m << " row " << n << " column board.\n"; 
    }

    return 0;
}

Co robi ta linijka 