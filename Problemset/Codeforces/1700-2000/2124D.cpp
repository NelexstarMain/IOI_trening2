#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vecin(aa, n);
    if (k == 1) {
        cout << "YES" << endl;
        return;
    }

    vector<int> bb = aa;
    sort(all(bb));
    int cutoff = bb[k - 2];
    vector<int> cc;
    for (auto a : aa)
        if (a <= cutoff)
            cc.push_back(a);
    int spare = cc.size() - k + 1;
    int L = 0, R = cc.size() - 1;
    bool bad = false;
    while (L < R) {
        if (cc[L] != cc[R]) {
            if (spare == 0) {
                bad = true; break;
            }
            if (cc[L] == cutoff) {
                L ++;
                spare --;
            } else if (cc[R] == cutoff) {
                R --;
                spare --;
            } else {
                bad = true; break;
            }
            continue;
        }
        L ++;
        R --;
    }
    if (bad) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;

    cin >> tt;

    while (tt--) solve();
    return 0;
}