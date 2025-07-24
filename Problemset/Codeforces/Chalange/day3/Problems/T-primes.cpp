#include <iostream>
#include <cmath>
#include <vector>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int& x: arr) std::cin >> x;

    for (int x: arr) {
        int num = floor(sqrt(x));
        if (x != num*num) {
            std::cout << "NO\n";
        } else if (is_prime(num)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }


    }   
}