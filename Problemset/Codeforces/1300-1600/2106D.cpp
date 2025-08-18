#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    // najpierw sprawdzamy bez dodawania
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (a[i] >= b[j]) j++;
    }
    if (j == m) {
        cout << 0 << "\n";
        return;
    }

    // znajdź pierwsze miejsce gdzie się zacięliśmy
    int need = b[j]; // Igor potrzebuje >= need w tym miejscu

    // spróbujmy "dodać" taki kwiat i iść dalej
    j++; // po dodaniu sztucznego kwiatu
    for (int i = 0; i < n && j < m; i++) {
        if (a[i] >= b[j]) j++;
    }
    if (j == m) {
        cout << need << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
