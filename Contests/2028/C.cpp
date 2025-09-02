#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define smx(a, b) a = max(a, b)
#define smn(a, b) a = min(a, b)
#define pb push_back
#define endl '\n'
 
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
 
mt19937 rng(time(0));
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		ll v; cin >> v;
		vector<ll> a(n);
		rep(i,0,n) cin >> a[i];
 
		vector<ll> sums(n + 1);
		rep(i,0,n) sums[i + 1] = sums[i] + a[i];
 
		auto query = [&](int i, int j) { // [i, j]
			return sums[j] - sums[i];
		};
 
		auto compute_pfx = [&]() -> vector<int> {
			vector<int> pfx(n + 1, 0);
			int end = 0;
			ll sum = 0;
			for (int start = 0; start < n; start++) {
				while (end < n && sum < v) {
					sum += a[end];
					++end;
					pfx[end] = max(pfx[end], pfx[end - 1]);
				}
				if (sum >= v) {
					pfx[end] = 1 + pfx[start];
				}
				sum -= a[start];
			}
			rep(i,1,n+1) {
				pfx[i] = max(pfx[i], pfx[i - 1]);
			}
			return pfx;
		};
 
		auto pfx = compute_pfx();
		reverse(all(a));
		auto sfx = compute_pfx();
		reverse(all(a));
		reverse(all(sfx));
 
		if (pfx[n] < m) {
			cout << "-1\n";
			continue;
		}
 
		int end = 0;
		ll ans = 0;
		for (int start = 0; start < n; start++) {
			while (end < n && pfx[start] + sfx[end + 1] >= m) ++end;
			if (pfx[start] + sfx[end] >= m)
				ans = max(ans, query(start, end));
		}
		cout << ans << "\n";
	}
}