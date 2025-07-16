#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    cout << b.size() << endl;
    return 0;
}


