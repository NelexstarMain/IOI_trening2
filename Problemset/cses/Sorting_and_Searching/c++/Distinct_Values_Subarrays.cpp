#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_set<int> window;
    int l = 0;
    long long result = 0;

    for (int r = 0; r < n; ++r) {
        while (window.count(a[r])) {
            window.erase(a[l]);
            ++l;
        }
        window.insert(a[r]);
        result += (r - l + 1);
    }

    cout << result << "\n";

    return 0;
}
