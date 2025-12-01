#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, moves = 0;
    std::string whole;
    std::cin >> n >> whole;

    for (int i = 1; i < n; i++) {
        if (whole[i] == whole[i - 1]) {
            moves++;
        }
    }

    std::cout << moves << '\n';
}
