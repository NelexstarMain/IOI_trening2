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

// void solve() {
//     int a, b; std::cin >> a >> b;
//     int c = 0;
//     std::vector<char> A = {
//         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
//         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
//     };
//     std::vector<std::string> B = {""};
//     int start = 0, s = 0;
//     while (s < a) { 
//         s = SIZE(B);
//         for (int i = start; i < s; i++) {
//             for (char x: A) {
//                 B.PB((B[i]+x));
//             }
//         }
//         start = s;
//     }
//     for (int i = 0; i < a; i++) {
//         std::cout << B[i] << " ";
//     }
//     std::cout << "\n";
// }
void solve() {
    int a, b; std::cin >> a >> b;

    for (int i = 0; i < b; i++) {
        std::string s = "";
        int temp = i;
        do {
            s += (char)('a' + (temp % 26));
            temp /= 26;
        } while (temp > 0);
        
        std::cout << s << (i == a - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
