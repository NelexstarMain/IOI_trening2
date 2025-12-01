#include <iostream>
#include <string>
#include <algorithm>
#include <climits> // dla INT_MAX

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t; 
    while (t--) {
        int minim = INT_MAX;
        std::string num;
        std::cin >> num;
        for (char x : num) {
            int c = x - '0';  
            minim = std::min(c, minim);
        }
        std::cout << minim << '\n';
    }

    return 0;
}
