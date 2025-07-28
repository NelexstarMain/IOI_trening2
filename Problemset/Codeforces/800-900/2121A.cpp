#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int n, s; std::cin >> n >> s;
        std::vector<int> arr(n);
        for (int& x: arr) std::cin >> x;
        int minimum = *std::min_element(arr.begin(), arr.end());
        int maximum = *std::max_element(arr.begin(), arr.end());


        std::cout << std::min(std::abs(s-minimum), std::abs(s-maximum)) + (maximum-minimum) << std::endl;



    }

}