#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int k, q, q_next; 
    if (!(cin >> k >> q >> q_next)) return;
    if (k == q) {
        cout << "Illegal state\n";
        return;
    }
    int kr = k / 8, kc = k % 8;
    int qr = q / 8, qc = q % 8;
    int nr = q_next / 8, nc = q_next % 8; 
    if (q == q_next) {
        cout << "Illegal move\n";
        return;
    }
    if (qr != nr && qc != nc) {
        cout << "Illegal move\n";
        return;
    }
    if (qr == nr) { 
        if (kr == qr) { 
            if ((q < k && k < q_next) || (q_next < k && k < q)) {
                cout << "Illegal move\n";
                return;
            }
        }
    } else { 
        if (kc == qc) {
            if ((q < k && k < q_next) || (q_next < k && k < q)) {
                cout << "Illegal move\n";
                return;
            }
        }
    }
    if (q_next == k) {
        cout << "Illegal move\n";
        return;
    }

    if ((kr == nr && abs(kc - nc) == 1) || (kc == nc && abs(kr - nr) == 1)) {
        cout << "Move not allowed\n";
        return;
    }
    bool king_can_move = false;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nkr = kr + dr[i];
        int nkc = kc + dc[i];
        if (nkr >= 0 && nkr < 8 && nkc >= 0 && nkc < 8) {
            if (nkr == nr && nkc == nc) continue;
            if (nkr == nr || nkc == nc) {
                continue;
            }
            king_can_move = true;
            break;
        }
    }

    if (king_can_move) {
        cout << "Continue\n";
    } else {
        cout << "Stop\n";
    }
}

int main() {
    fast_io();
    while (!cin.eof()) {
        solve();
        cin >> ws; 
        if (cin.peek() == EOF) break;
    }
    return 0;
}