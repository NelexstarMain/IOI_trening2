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
    std::string l;
    std::string a = "";
    while (std::getline(std::cin, l) && l != "END") a += (' ' + l);
    for (char& x: a) if (!std::islower(x)) x = ' ';
    // std::cout << a << "\n";
    std::stringstream ss(a);
    std::set<std::string> B;

    std::vector<pii> C;
    std::vector<std::string> E;

    std::map<std::string, int> D;

    std::string curr;
    while (ss >> curr) { E.PB(curr); B.insert(curr); }
    D[E[0]]++;
    int Left = 0, Right = 0; 
    while (Right < SIZE(E)) {
        if (SIZE(D) == SIZE(B)) {
            C.PB({Right - Left, Left + 1});
            D[E[Left]]--;
            if (D[E[Left]] == 0) D.erase(E[Left]);
            Left++;
        } else {
            Right++;
            if (Right < SIZE(E)) D[E[Right]]++;
        }
    }
    std::sort(ALL(C));
    std::cout << "Document " << z << ": " << C[0].S << " " << C[0].S+C[0].F << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    int z = 1;
    while (T--) solve(z++);
    return 0;
}
