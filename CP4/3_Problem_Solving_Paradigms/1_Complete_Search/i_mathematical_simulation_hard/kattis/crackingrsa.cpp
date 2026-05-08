#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

set<int> FN;
std::set<int> get_primes(int n) {
    if (n < 2) return {};
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) is_prime[i] = false;
        }
    }
    std::set<int> primes;
    for (int p = 2; p <= n; p++) if (is_prime[p]) primes.insert(p); 
    return primes;
}

void solve() {
    ll N, E; cin >> N >> E;
    ll q, p;
    for (int x: FN) {
        if (N%x==0 && FN.find(N/x)!=FN.end()){
            q=x; p=N/x;
            break;
        }
    }
    ll S=(q-1)*(p-1);
    for (ll i=1; i<=S; i++) {
        if ((i*E)%S==1) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    fast_io();
    FN=get_primes(1001);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
