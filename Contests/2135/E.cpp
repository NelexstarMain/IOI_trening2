#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 998244353;

struct DSU {
    vector<int> parent;
    vector<int> xor_val;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        xor_val.assign(n, 0);
    }

    pair<int, int> find(int i) {
        if (parent[i] == i) {
            return {i, 0};
        }
        auto [root, val] = find(parent[i]);
        parent[i] = root;
        xor_val[i] ^= val;
        return {root, xor_val[i]};
    }

    bool unite(int u, int v, int required_xor) {
        auto [root_u, val_u] = find(u);
        auto [root_v, val_v] = find(v);

        if (root_u == root_v) {
            if ((val_u ^ val_v) != required_xor) {
                return false;
            }
        } else {
            parent[root_v] = root_u;
            xor_val[root_v] = val_u ^ required_xor ^ val_v;
        }
        return true;
    }
};

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    long long V;
    cin >> n >> m >> V;
    vector<int> a(n);
    bool has_unknown = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            has_unknown = true;
        }
    }

    DSU dsu(n + 1);

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            if (!dsu.unite(i, n, a[i])) {
                cout << 0 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (!dsu.unite(u, v, 0)) {
            cout << 0 << endl;
            return;
        }
    }

    int free_components = 0;
    
    // Check if the virtual node is connected to any others
    bool connected_to_fixed = false;
    for(int i = 0; i < n; ++i) {
        if(dsu.find(i).first == dsu.find(n).first) {
            connected_to_fixed = true;
            break;
        }
    }

    if (connected_to_fixed) {
        for(int i = 0; i < n; ++i) {
            if(dsu.parent[i] == i) {
                 if(dsu.find(i).first != dsu.find(n).first) {
                     free_components++;
                 }
            }
        }
    } else {
        for(int i = 0; i < n; ++i) {
            if(dsu.parent[i] == i) {
                free_components++;
            }
        }
    }

    if (!has_unknown) {
        cout << 1 << endl; // A fixed graph with no contradictions has only one way
        return;
    }

    // Poprawna linia
    cout << power(V, free_components) << endl;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}