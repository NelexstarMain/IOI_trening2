#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string word;
    std::cin >> word;

    int upper = 0, lower = 0;
    for (char c : word) {
        if (std::isupper(c)) upper++;
        else if (std::islower(c)) lower++;
    }

    for (char &c : word) {
        if (upper > lower)
            c = std::toupper(c);
        else
            c = std::tolower(c);
    }

    std::cout << word << '\n';
    return 0;
}
