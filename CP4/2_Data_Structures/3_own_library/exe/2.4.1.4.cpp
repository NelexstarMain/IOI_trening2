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

using edge = std::tuple<int, int, int>; 
using AdjacencyMatrix = std::vector<std::vector<int>>;
using AdjacencyList   = std::vector<std::vector<pii>>;
using EdgeList        = std::vector<edge>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


AdjacencyMatrix AM(V, std::vector<int>(V, 0));
AdjacencyList AL(V);
EdgeList EL;


EdgeList AM_EL(AdjacencyMatrix& A) {
    int V = SIZE(A);
    EdgeList NEW;
    FWD(i, 0, V) {
        FWD(j, 0, V) {
            if (A[i][j] != 0) NEW.PB({i, j, A[i][j]});
        }
    }
    return NEW;
}


EdgeList AL_EL(AdjacencyList& A) {
    int V = SIZE(A);
    EdgeList NEW;
    FWD(u, 0, V) {
        for (auto &e : A[u]) {
            NEW.PB({u, e.F, e.S});
        }
    }
    return NEW;
}


AdjacencyList EL_AL(EdgeList& A, int V) {
    AdjacencyList NEW(V);
    for (auto &e : A) {
        auto [u, v, w] = e;
        NEW[u].PB({v, w});
    }
    return NEW;
}


AdjacencyMatrix EL_AM(EdgeList& A, int V) {
    AdjacencyMatrix NEW(V, vector<int>(V, 0));
    for (auto &e : A) {
        auto [u, v, w] = e;
        NEW[u][v] = w;
    }
    return NEW;
}


AdjacencyMatrix AL_AM(AdjacencyList& A) {
    int V = SIZE(A);
    AdjacencyMatrix NEW(V, vector<int>(V, 0));
    FWD(i, 0, V) {
        for (auto &curr : A[i]) {
            NEW[i][curr.F] = curr.S;
        }
    }
    return NEW;
}


void solve() {
    //AM->AL AL->AM AM->EL El->AM AL->EL El->AL

}

int main() {
    fast_io();
    int t = 1;
    if(!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
