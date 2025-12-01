#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int& x : arr) std::cin >> x;

    int count = 1;  
    std::unordered_set<int> found;
    std::unordered_set<int> elements;
    elements.insert(arr[0]);

    for (int i = 1; i < n; i++) {
        if (elements.find(arr[i]) != elements.end()) {
            elements.erase(arr[i]);
        }
        found.insert(arr[i]);  

        if (elements.empty()) {
            count++;
            elements = found;
            found.clear();
        }
    }


    std::cout << count << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
}
