#include <iostream>
#include <cmath>
#include <vector>

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;

    std::vector<long long> arr(n);
    for (long long& x: arr) std::cin >> x;

    for (long long x: arr) {
        long long num = std::sqrt(x);
        if (num * num != x) {
            std::cout << "NO\n";
        } else if (is_prime(num)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }   
}
