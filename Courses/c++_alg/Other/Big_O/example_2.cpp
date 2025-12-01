#include <iostream>
using namespace std;

void multiply(int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            cout << i*j << endl;
        }
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    multiply(x, y);
    cin >> x;
    return 0;  
}