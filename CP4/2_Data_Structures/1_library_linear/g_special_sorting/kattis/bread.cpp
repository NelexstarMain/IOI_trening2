#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll inv_a = count_inversions(a, 0, n - 1);
    ll inv_b = count_inversions(b, 0, n - 1);
    if (inv_a % 2 == inv_b % 2) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}