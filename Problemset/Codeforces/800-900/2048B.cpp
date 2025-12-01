#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> a(n, 0);

    // Wstawiamy liczby co k kroków
    int first = k - 1;
    int curr = 1;
    while (first < n - 1) {
        a[first] = curr++;
        first += k;
    }
    a[n - 1] = curr++;

    // Uzupełniamy brakujące zera kolejnymi liczbami
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = curr++;
        }
    }

    // Wypisywanie wyniku
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
