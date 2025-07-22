#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maximum = 0, in_train = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int enter = 0, out = 0;
        cin >> out >> enter;
        in_train -= out;
        in_train += enter;
        maximum = max(maximum, in_train);
    }
    cout << maximum << endl;
}

