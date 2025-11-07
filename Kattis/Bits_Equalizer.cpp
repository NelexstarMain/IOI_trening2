#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(int cs) {
    string s, t;
    cin >> s >> t;

    int cnt01 = 0, cnt10 = 0, cntq = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0' && t[i] == '1') cnt01++;
        else if (s[i] == '1' && t[i] == '0') cnt10++;
        else if (s[i] == '?') cntq++;
    }

    // sprawdzamy, czy da się osiągnąć t
    int s_ones = count(s.begin(), s.end(), '1');
    int t_ones = count(t.begin(), t.end(), '1');
    if (s_ones > t_ones) {
        cout << "Case " << cs << ": -1\n";
        return;
    }

    // ruchy: zamiana ? → coś, zmiana 0→1, i ewentualne swapy
    int swaps = min(cnt01, cnt10);
    int remain = abs(cnt01 - cnt10);
    int moves = cntq + swaps + remain;

    cout << "Case " << cs << ": " << moves << "\n";
}

int main() {
    fast_io();
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        solve(cs);
    }
    return 0;
}