#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main() {
    int T; std::cin >> T;

    while (T--) {
        std::string n; std::cin >> n;
        std::vector<int> a;
        for (char x: n) {
            int c = x - '0';
            a.push_back(c);
        }
        std::sort(a.begin(), a.end());
        std::vector<int> ideal;

        for (int i = 1; i <= 10; i++) {
            int ide = 10 - i;
            for (int j = 0; j < a.size(); ) {  
                if (a[j] >= ide) {
                    ideal.push_back(a[j]);
                    a.erase(a.begin() + j);
                    break;
                } else {
                    ++j;  
                }
            }
        }

        for (int x: ideal) {
            std::cout << x;
        }
        std::cout << "\n";
    }
}