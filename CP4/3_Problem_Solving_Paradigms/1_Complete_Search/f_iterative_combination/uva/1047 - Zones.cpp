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
    int N, M; 
    int z=1;
    while (cin >> N >> M) {
        if (N==0&&M==0) return;
        vector<int> R(N); for (int &x: R) cin >> x;
        int Q; cin >> Q;
        map<vector<int>, int> A;
        while (Q--) {
            int S; cin >> S;
            vector<int> B(S); for (int &x: B) cin >> x;
            int C; cin >> C;
            A.insert({B, C});
        }
        vector<int> Bit(N, 0);
        for (int i=0; i<M; i++) Bit[N-i-1]=1;
        int Smax=-INF;
        vector<int> Vmax;
        do {
            int Sum=0;
            for (int i=0; i<N; i++) {
                if (Bit[i]) Sum+=R[i];
            }
            // cout << Sum << "\n";
            for (auto const& entry : A) {
                const vector<int>& key = entry.first;
                int value = entry.second;
                int count=0;
                for (int i=0; i<SIZE(key); i++) if (Bit[key[i]-1]) count++;
                if (count > 0) Sum-=((count-1)*value);
                // cout << count << " " << value << "\n";
            }
            if (Sum>=Smax) {
                Smax=Sum;
                Vmax=Bit;
            }

        } while (next_permutation(ALL(Bit)));
        cout << "Case Number  " << z++ << "\n";
        cout << "Number of Customers: " << Smax << "\n";
        cout << "Locations recommended:";
        for (int i=0; i<N; i++) if (Vmax[i]) cout << " " << i+1;
        cout << "\n\n"; 
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
