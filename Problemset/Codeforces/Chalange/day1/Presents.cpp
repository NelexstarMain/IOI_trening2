#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> array(n);

    for (int i = 1; i <= n; i++) {
        int element;
        std::cin >> element;
        array[element-1] = i; 
    }

    for (int x: array) {
        std::cout << x << " ";
    }
}