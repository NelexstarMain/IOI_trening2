#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int& x: a) cin >> x;

    int i = 1;

    while (i<m) {
        i += a[i-1];
        
        if (i == m) {
            cout << "Yes" << endl;
            return 0;
        } 
    }
    cout << "No" << endl;
    return 0;
}

