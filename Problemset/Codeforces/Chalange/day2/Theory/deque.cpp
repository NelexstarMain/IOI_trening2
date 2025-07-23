#include <iostream>
#include <deque>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> de;

    for (int i = 1; i <= 11; i++) {
        if (i%2 == 0) {
            de.push_back(i);
        } else {
            de.push_front(i);
        }
    }

    for (int x: de) {
        cout << x << endl;
    }
    
    return 0;
}
