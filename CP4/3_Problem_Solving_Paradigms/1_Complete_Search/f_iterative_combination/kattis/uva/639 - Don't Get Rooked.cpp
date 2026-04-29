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

int N;

bool valid(vector<int> &A) {
    for (int i=0; i<N*N; i++) {
        if (A[i]==1) {
            //right
            int x=i+1;
            while ((x/N)==(i/N) && (x<N*N) && (A[x]!=-1)) {
                if (A[x]==1) return false;
                x++;
            }
            // down
            x=i+N;
            while ((x<N*N) && (A[x]!=-1)) {
                if (A[x]==1) return false;
                x+=N;
            }
        }
    }
    return true;
}

void solve() {
    while (cin>>N && N>0) {
        vector<int> A, B;
        for (int i=0; i<N*N; i++) B.PB(i);
        for (int i=0; i<N; i++) {
            string l; cin >> l;
            for (int j=0; j<N; j++) if (l[j]=='X') {
                A.PB(i*N+j); B.erase(remove(ALL(B), i*N+j), B.end()); 
            }
        }
        int best=-INF;
        int M=(1<<SIZE(B));
        for (int i=0; i<M; i++) {
            vector<int> Map(N*N);
            for (int x: A) Map[x]=-1;
            for (int j=0; j<SIZE(B); j++) {
                int mask=(1<<j);
                if ((mask&i)>0) Map[B[j]]=1;
            }
            if (valid(Map)) best=max(best, __builtin_popcount(i));
        }
        cout << best << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
