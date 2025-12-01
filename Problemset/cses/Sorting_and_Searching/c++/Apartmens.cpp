#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int count = 0, j = 0;
    vector<int> a(n), b(m);  

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int x: a) {    
        while (j<m && b[j] < x - k) {
            j++;
        }
        if (j < m && b[j] >= x - k && b[j] <= x + k) {
            count++;
            j++;
        }

    }
    cout << count << endl;
}


