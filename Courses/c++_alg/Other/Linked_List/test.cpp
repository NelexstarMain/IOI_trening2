#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> list;



    for (int& x: list) cin >> x;

    for (int x: list) {
        cout << x << endl;
    }
    return 0;
}
