#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define PB push_back
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

vi currentM(8);
vector<vi> allP;

bool canPlace(int r, int c) {
    for (int i = 0; i < c; i++) {
        if (currentM[i] == r || abs(currentM[i] - r) == abs(i - c)) 
            return false;
    }
    return true;
}

void abc(int c) {
    if (c == 8) {
        allP.PB(currentM);
        return;
    }
    for (int r = 1; r <= 8; r++) {
        if (canPlace(r, c)) {
            currentM[c] = r;
            abc(c + 1);
        }
    }
}

void solve(int t_case, int total_t) {
    int x, y; 
    if(!(cin >> x >> y)) return;
    vector<vi> R;
    for (auto v : allP) {
        if (v[y-1] == x) R.PB(v);
    }
    sort(ALL(R));

    cout << "SOLN       COLUMN" << "\n";
    cout << " #      1 2 3 4 5 6 7 8" << "\n\n";

    for (int i = 0; i < SIZE(R); i++) {
        printf("%2d      ", i + 1); 
        for (int j = 0; j < 8; j++) {
            printf("%d%s", R[i][j], (j == 7 ? "" : " "));
        }
        printf("\n");
    }
    
    if (t_case < total_t - 1) cout << "\n";
}

int main() {
    abc(0);
    int T; 
    if(!(cin >> T)) return 0; 
    for(int i = 0; i < T; i++) {
        solve(i, T);
    }
    
    return 0;
}