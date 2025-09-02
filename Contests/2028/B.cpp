#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		ll n, b, c; cin >> n >> b >> c;
		if (b == 0) {
			if (c >= n) {
				cout << n << "\n";
			} else if (c >= n - 2) {
				cout << n - 1 << "\n";
			} else {
				cout << -1 << "\n";
			}
		} else {
		if (c >= n) cout << n << "\n";
		else cout << n - max(0ll, 1 + (n - c - 1) / b) << "\n";
		}
	}
}