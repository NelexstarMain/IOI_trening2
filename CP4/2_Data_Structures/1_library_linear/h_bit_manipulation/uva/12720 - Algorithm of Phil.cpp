#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(int z) {
    string a; cin >> a;
    int n = SIZE(a);
    int mid = (n + 1) / 2;
    
    string F = a.substr(0, mid);
    string S = a.substr(mid);
    reverse(ALL(S));

    ll res = 0;
    while (SIZE(F) || SIZE(S)) {
        char c;
        if (SIZE(F) > SIZE(S)) {
            c = F.back(); F.pop_back();
        } else if (SIZE(S) > SIZE(F)) {
            c = S.back(); S.pop_back();
        } else {
            if (S.back() > F.back()) {
                c = S.back(); S.pop_back();
            } else {
                c = F.back(); F.pop_back();
            }
        }
        res = (res * 2 + (c - '0')) % MOD;
    }
    cout << "Case #" << z << ": " << res << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    int z = 1;
    while (T--) solve(z++);
    return 0;
}