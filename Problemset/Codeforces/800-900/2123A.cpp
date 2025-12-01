#include <iostream>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        if (n <= 2){
            std::cout << "Alice";
        } else if (n%4 == 0) {
            std::cout << "Bob";
        } else {
            std::cout << "Alice";
        }
        std::cout << std::endl;
    }
}