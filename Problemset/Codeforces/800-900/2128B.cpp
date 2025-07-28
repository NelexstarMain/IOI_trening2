#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        int l = 0, r = n-1;
        std::vector<int> arr(n);
        std::vector<char> res;
        for (int& x: arr) std::cin >> x;
        for (int i = 1; i <= n; i++) {
            bool takeLeft;
            if (i%2 == 1) {
                takeLeft = arr[l] < arr[r];
            } else {
                takeLeft = arr[l] > arr[r];
            }
            if (takeLeft) {
                res.push_back('L');
                l++;
            } else {
                res.push_back('R');
                r--;
            }
        }
        for (char c : res) std::cout << c;
        std::cout << '\n';
    }
}