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
    int n; std::cin >> n;
    std::set<int> A;
    std::vector<int> B(n+7, 0); // Tworzy liste z wartosciami depht dla kazdego wierzchołka + 7 offset
    ll c = 0;
    for (int i = 0; i < n; i++) {
        int curr; std::cin >> curr;
        if (i == 0) { // Pierwszy przypadek jest inny ponieważ on bedzie kożeniem
            A.insert(curr);
            B[curr] = 0;
            cout << "0\n";
            continue;
        }

        auto it = A.lower_bound(curr); int dep = 0; // Najmniejszy wiekszy od <curr>
        if (it != A.end()) dep = std::max(dep, B[*it]); // Jesli iterator jest mniejszy niż end czyli jesli znaleziono element wiekszy od niego to sprawdza głebokosc
        if (it != A.begin()) { it = std::prev(it); dep = std::max(dep, B[*it]); } // jesli iterator był znaleziony i był wiekszy od 0 to cofamy iterator o 1 element i sprawdzamy to bedzie największy mniejszy od tego elementu
        
        // int dep = std::max(B[*A.lower_bound(curr)], B[*A.upper_bound(curr)]) + 1;
        dep++; // Musimy przesunąć do przodu ponieważ to musi być dziecko albo wiekszego albo mniejszego 
        B[curr] = dep; c += dep;
        A.insert(curr);
        std::cout << c << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
