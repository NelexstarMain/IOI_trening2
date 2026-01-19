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

ll merge_and_count(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    ll inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv_count;
}

ll count_inversions(vector<int>& arr, int left, int right) {
    ll count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += count_inversions(arr, left, mid);
        count += count_inversions(arr, mid + 1, right);
        count += merge_and_count(arr, left, mid, right);
    }
    return count;
}

void solve() {
    int n; 
    while (std::cin >> n && n > 0) {
        std::vector<int> a;
        for (int i = 0; i < n; i++) {
            int c; std::cin >> c;
            a.PB(c);
        }
        ll inv = count_inversions(a, 0, SIZE(a)-1);
        std::cout << inv << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
