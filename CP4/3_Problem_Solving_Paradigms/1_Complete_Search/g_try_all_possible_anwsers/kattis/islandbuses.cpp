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

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

vector<int> change1(string &A) {
    vector<int> B;
    for (char x: A) {
        if (x=='#') B.PB(1);
        else if (x=='X') B.PB(2);
        else if (x=='B') B.PB(3);
        else B.PB(0);
    }
    return B;
}

bool check(int x, int y, int cx, int cy) {
    return (0<=cx && 0<=cy && cx<x && cy<y);
}

int flood(vector<vector<int>> A, set<int> Food) {
    int counter = 0;
    int X = SIZE(A), Y = SIZE(A[0]);
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (A[i][j] != 0 && Food.count(A[i][j])) {
                counter++;
                queue<pair<pii, int>> C; 
                C.push({{i, j}, A[i][j]});
                A[i][j] = 0;

                while (!C.empty()) {
                    auto curr = C.front(); C.pop();
                    int curr_x = curr.F.F;
                    int curr_y = curr.F.S;
                    int curr_val = curr.S;

                    for (int d = 0; d < 4; d++) {
                        int CX = curr_x + DIR[d][0], CY = curr_y + DIR[d][1];
                        
                        if (check(X, Y, CX, CY) && A[CX][CY] != 0 && Food.count(A[CX][CY])) {
                            if (abs(curr_val - A[CX][CY]) <= 1) {
                                C.push({{CX, CY}, A[CX][CY]});
                                A[CX][CY] = 0; 
                            }
                        }
                    } 
                }
            }
        }
    }
    return counter;
}

void solve() {
    string l;
    int second=1;;
    while (getline(cin, l)) {
        if (second!=1) cout << "\n";
        vector<vector<int>> A;
        A.PB(change1(l));
        while (getline(cin, l) && !l.empty()) A.PB(change1(l));
        cout << "Map " << second++ << "\n";
        cout << "islands: " << flood(A, {1, 2}) << "\n";
        cout << "bridges: " << flood(A, {3}) << "\n";
        cout << "buses needed: " << flood(A, {1, 2, 3}) << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
