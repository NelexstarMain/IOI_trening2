#include <iostream>
// #include <vector>
// #include <algorithm>
#include <array>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> arr = {21, 23, 54};

    for (int& x: arr) {
        x = x*x;
    }

    for (int x: arr) {
        cout << x << endl;
    }
    return 0;
}
