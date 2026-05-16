#include <bits/stdc++.h>

using namespace std;

int F2(int n) {
    return 2 * (n - (1 << (int) log2(n))) + 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int x = n, ans = 0;
        while (x != F2(x)) {
            ans += x - F2(x);
            x = F2(x);
        }
        ans += 2 * x; 
        cout << ans << '\n';
    }
    return 0;
}