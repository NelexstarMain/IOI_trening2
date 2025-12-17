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
    int n; 
    if (!(cin >> n)) return; 
    if (n == 0) return;

    vector<string> notes;
    int lenght = 0;
    for (int i = 0; i < n; i++) {
        string curr; cin >> curr;
        int dur = 1;
        if (SIZE(curr) > 1) {
            dur = stoi(curr.substr(1));
        }
        lenght += dur + 1;
        notes.PB(curr);
    }
    if (lenght > 0) lenght--;
    string pitch_order = "GFEDCBAgfedcba";
    vector<vector<char>> staff(14, vector<char>(lenght, ' '));
    for (int i = 0; i < 14; i++) {
        char p = pitch_order[i];
        if (p == 'F' || p == 'D' || p == 'B' || p == 'g' || p == 'e' || p == 'a') {
            for (int j = 0; j < lenght; j++) {
                staff[i][j] = '-';
            }
        }
    }
    int current_col = 0;
    for (const string& s : notes) {
        char pitch = s[0];
        int dur = 1;
        if (s.size() > 1) {
            dur = stoi(s.substr(1));
        }
        int row_idx = -1;
        for(int i = 0; i < 14; i++) {
            if(pitch_order[i] == pitch) {
                row_idx = i;
                break;
            }
        }
        if (row_idx != -1) {
            for (int k = 0; k < dur; k++) {
                staff[row_idx][current_col + k] = '*';
            }
        }
        current_col += dur + 1;
    }
    for (int i = 0; i < 14; i++) {
        cout << pitch_order[i] << ": ";
        for (int j = 0; j < lenght; j++) {
            cout << staff[i][j];
        }
        cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}