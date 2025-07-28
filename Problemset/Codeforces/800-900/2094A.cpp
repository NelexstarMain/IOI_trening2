#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    std::cin.ignore();

    while (T--) {
        std::string st;
        std::getline(std::cin, st);

        std::string res;

        std::stringstream ss(st);
        std::vector<std::string> words((std::istream_iterator<std::string>(ss)), std::istream_iterator<std::string>());

        for (auto word : words) {
            if (!word.empty()) {
                res += word[0];
            }
        }
        std::cout << res << "\n";
    }
    return 0;
}