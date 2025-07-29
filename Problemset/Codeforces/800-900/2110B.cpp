#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) {
        std::string brc; std::cin >> brc;
        int bal = 0;
        bool valid = true;

        for (int i = 1; i + 1 < brc.size(); i++) {
            char second = brc[i];
            if (second == '(') {
                bal++;
            } else {
                bal--;
            }
            if (bal < 0) {
                valid = false;
            }
        }

        std::cout << (valid ? "NO" : "YES") << '\n';
    }
}
