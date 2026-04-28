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

    vector<int> C(6);

    int MBash(vector<int> &Order, vector<vector<int>> &A) {
        int I=0;
        vector<map<int, int>> B(SIZE(Order)+1); // message ( start bit, end bit ) 
        int Count=0, M=-INF;
        for (int x: Order) {
            int Sent=0, Look=1; // how much pieces was sent, the smallest bit we look for
            // cout << C[x] << "\n";
            while (Sent<C[x]) {
                if (B[x].find(Look)!=B[x].end()) {
                    Count-=((B[x][Look]-Look)+1);
                    int L=Look;
                    Sent++; Look=(B[x][L]+1);
                    B[x].erase(L); 
                } else {
                    int m=A[I][0], s=A[I][1], e=A[I][2];
                    if (m!=x||s!=Look) {
                        B[m].insert({s, e});
                        Count+=(e-s)+1;
                    }
                    else {
                        Sent++;
                        Look=e+1;
                    }
                    I++;
                }
                M=max(M, Count);
            }
        }
        return M;
    }

    void solve() {
        int N, M;
        int V=1;
        while (cin >> N >> M) {
            if (N==0&&M==0) return;
            cout << "Case " << V++ << ": ";
            for (int i=0; i<N; i++) { int z; cin >> z; }
            C.assign(N+1, 0);
            vector<vector<int>> A;
            for (int i=0; i<M; i++) {
                int m, s, e; cin >> m >> s >> e; 
                A.PB({m, s, e}); C[m]++;
                // cout << C[m] << " d\n";
            }
            vector<int> B(N); for (int i=0; i<N; i++) B[i]=(i+1);
            vector<int> Res;
            do {
                Res.PB(MBash(B, A));
            } while (next_permutation(ALL(B)));
            cout << *(min_element(ALL(Res))) << "\n\n"; 
        }
    }

    int main() {
        fast_io();
        solve();
        return 0;
    }
