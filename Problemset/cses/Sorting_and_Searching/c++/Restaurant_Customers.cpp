#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<pair<int,int>> events; 

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.emplace_back(a, +1); 
        events.emplace_back(b, -1);  
    }


    sort(events.begin(), events.end());

    int current = 0, maximum = 0;
    for (auto& e : events) {
        current += e.second;          
        if (current > maximum)
            maximum = current;
    }

    cout << maximum << "\n";

    return 0;
}
