#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to find the modular inverse using Fermat's Little Theorem
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

// Function to find the smallest prime p such that k % p != 0
long long find_suitable_prime(long long k) {
    std::vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (long long p : primes) {
        if (k % p != 0) {
            return p;
        }
    }
    return 101;
}

void solve() {
    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long p = find_suitable_prime(k);
    long long k_rem = k % p;
    long long k_inv = modInverse(k_rem, p);

    for (int i = 0; i < n; ++i) {
        long long a_rem = a[i] % p;
        if (a_rem == 0) {
            continue;
        }

        long long needed_rem = (p - a_rem) % p;
        long long m = (needed_rem * k_inv) % p;
        a[i] += m * k;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}