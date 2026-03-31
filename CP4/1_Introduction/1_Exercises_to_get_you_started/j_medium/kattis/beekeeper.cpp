#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool is_vowel(char c) {
    string v = "aeiouy";
    return v.find(c) != string::npos;
}

void solve() {
    int n; 
    cin >> n;
    if (n == 0) exit(0);

    vector<string> w(n);
    for (auto &s : w) cin >> s;

    int best = -1;
    string res;

    for (auto &x : w) {
        int cnt = 0;
        for (int i = 0; i + 1 < (int)x.size(); ) {
            if (is_vowel(x[i]) && x[i] == x[i + 1]) {
                cnt++;
                i += 2;  // przeskakujemy parę
            } else {
                i++;
            }
        }

        if (cnt > best) {
            best = cnt;
            res = x;
        }
    }

    cout << res << "\n";
}

int main() {
    fast_io();
    while (true) solve();
    return 0;
}
