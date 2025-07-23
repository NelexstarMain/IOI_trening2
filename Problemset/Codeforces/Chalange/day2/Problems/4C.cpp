#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, int> dict;

    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        if (dict.find(word) != dict.end()) {
            std::cout << word << dict[word] + 1 << '\n';
            dict[word] += 1;
        } else {
            std::cout << "OK\n";
            dict[word] = 0;
        }
    }

    return 0;
}
