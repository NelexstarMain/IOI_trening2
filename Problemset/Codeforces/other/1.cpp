#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int happy = 0, last = 0, need = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        while (sum >= need) {
            sum -= need;
            last++;
            need = 8 * last;
            if (need == 0) need = 1;
        }
        if (sum == 0) happy++;
    }
    cout << happy << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
