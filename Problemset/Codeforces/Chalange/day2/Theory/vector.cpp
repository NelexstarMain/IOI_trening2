#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 13;

    vector<int> vec;
    
    for (int i = 0; i < n; i++) {
        vec.push_back(i);
    }
    

    for (int x: vec) {
        cout << x << endl;
    }
    return 0;
}
