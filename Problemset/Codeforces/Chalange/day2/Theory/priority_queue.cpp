#include <iostream>

// #include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> pq;

    for (int i = 0; i < 10; i++) {
        pq.push(i);
    }

    while (!pq.empty()) {
        cout << "biggest " << pq.top() << endl;
        pq.pop();
    }   
    
    return 0;
}
