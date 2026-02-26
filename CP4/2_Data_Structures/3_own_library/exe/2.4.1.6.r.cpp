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

// W tej sekcji zakładamy, że sąsiedzi wierzchołka w Liście Sąsiedztwa 
// (Adjacency List) są wymienieni w porządku rosnącym według numerów wierzchołków 
// (jako że Macierz Sąsiedztwa poniekąd wymusza taką kolejność, a w Liście Krawędzi pojęcie sąsiadów wierzchołka nie istnieje). Co w przypadku,
//  gdy w danych wejściowych sąsiedzi nie są wymienieni w porządku rosnącym, a my preferujemy, 
//  aby byli oni posortowani w naszych obliczeniach? Jaka jest Twoja najlepsza implementacja?

void solve() {
    int n, m; std::cin >> n >> m;
    // 1. Zrobić w AL set żeby krawedzie były automatycznie posortowane ale do tak srednich wielkosci 
    std::vector<std::set<pii>> A(n);
    // 2. Posortować po dodaniu wszyskiego, (niezawsze bedzie działać)
    // gdyż czasem trzeba dynamiczne co przy sorotwaniu przy kazdym dodaniu by dało TLE
    std::vector<std::vector<pii>> B(n);
    for (int i = 0; i < n; i++) {
        int u, v, w; std::cin >> u >> v >> w;
        pii curr = {v, w};
        A[u].insert(curr); B[u].PB(curr);
        std::sort(ALL(B[u])); // O(E^2logV)
    }
    // albo posortuj po dodaniu to jest statyczna opcjia
    for (auto x: B) std::sort(ALL(x)); // O(ElogV)
} 

int main() {
    fast_io();
    solve();
    return 0;
}
