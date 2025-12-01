#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string word;
    std::cin >> word;

    for (char l : word) { // Użycie pętli for-each jest bardziej idiomatyczne i czytelne
        if (l == 'H' || l == 'Q' || l == '9' ){
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    
    return 0;
}