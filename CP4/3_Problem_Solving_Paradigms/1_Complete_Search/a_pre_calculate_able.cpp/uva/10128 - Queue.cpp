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
    static int results[14][14][14]; 
    memset(results, 0, sizeof(results));

    for (int i = 1; i <= 13; i++) {
        vector<int> A(i);
        for (int j = 0; j < i; j++) A[j] = j;
        int* data = A.data();

        do {
            int maxL = -1, countL = 0;
            for (int j = 0; j < i; j++) {
                if (data[j] > maxL) {
                    maxL = data[j];
                    countL++;
                }
            }

            int maxR = -1, countR = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (data[j] > maxR) {
                    maxR = data[j];
                    countR++;
                }
            }
            
            results[i][countL][countR]++;

        } while (next_permutation(A.begin(), A.end()));
        
        cerr << "Done for N = " << i << endl; 
    }
    // cout << results[10][4][4] << "\n" << results[11][3][1] << "\n" << "\n";
    cout << "{\n";
    for (int i=0; i<14; i++) {
        cout << "{ ";
        for (int j=0; j<14; j++) {
            cout << "{";
            for (int x: results[i][j]) cout << x << ",";
            cout << "}, ";
        }
        cout << "}, ";
    }
    cout << "}\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
