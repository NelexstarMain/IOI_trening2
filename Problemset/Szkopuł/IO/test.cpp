#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file1("wynik.out");
    std::ifstream file2("prz0d.out");

    if (!file1 || !file2) {
        std::cerr << "Nie mozna otworzyc plików!\n";
        return 1;
    }

    std::stringstream buffer1, buffer2;
    buffer1 << file1.rdbuf();
    buffer2 << file2.rdbuf();

    std::string content1 = buffer1.str();
    std::string content2 = buffer2.str();

    if (content1 == content2) {
        std::cout << "Pliki sa identyczne.\n";
    } else {
        std::cout << "Pliki różnią się.\n";
    }

    return 0;
}
