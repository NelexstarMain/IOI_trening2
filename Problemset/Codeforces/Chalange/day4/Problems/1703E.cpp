#include <iostream>
#include <vector>

int make

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> arr;

    for (int i = 0; i < n; i++) {
        std::vector<int> a;
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }

}
