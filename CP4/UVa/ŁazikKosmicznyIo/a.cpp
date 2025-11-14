#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(ll x) {
    if(x < 2) return false;
    for(ll i = 2; i*i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

ll next_prime_not_dividing(ll n, ll avoid = -1) {
    ll x = 2;
    while(true) {
        if(is_prime(x) && n % x != 0 && x != avoid)
            return x;
        x++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    if (n != m && (n%m!=0 && m%n!=0)) {
        if (std::gcd(n, m) == 1) {
            std::cout << "2\nDP\n";
        } else {
            ll x = next_prime_not_dividing(n);      
            ll y = next_prime_not_dividing(m, x);   

            string D(x, 'D');
            string R(y, 'P');
            int size = D.size() + R.size();
            if (size > std::min(n, m)+1) {
                if (n < m) {
                    D = string(n, 'D');
                    R = string(1, 'P');
                } else {
                    D = string(1, 'D');
                    R = string(m, 'P');
                }
            }
            cout << size << "\n";
            cout << D + R << "\n";
        }
    } else {
        if (n%2==1 || m%2==1) {
            if (n%2==1) {
                std::string D(std::floor(n/2), 'D');
                std::string R(std::floor(n/2)+1, 'P');
                std::cout << D.size() + R.size() << "\n";
                std::cout << D + R << "\n";
            } else {
                std::string D(std::floor(m/2), 'P');
                std::string R(std::floor(m/2)+1, 'D');
                std::cout << D.size() + R.size() << "\n";
                std::cout << D + R << "\n";
            }
        } else {
            if (n < m) {
                std::string D(n, 'D');
                std::string R(1, 'P');
                std::cout << D.size() + R.size() << "\n";
                std::cout << D + R << "\n";
                return 0;
            }
            std::string D(m, 'P');
            std::string R(1, 'D');
            std::cout << D.size() + R.size() << "\n";
            std::cout << D + R << "\n";
        }
        
        return 0;
}

}

    
