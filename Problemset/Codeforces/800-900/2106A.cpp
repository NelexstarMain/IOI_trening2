#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string num;
        std::cin >> n >> num;

        int count = 0; 

        for (int i = 0; i < n; i++) {
            std::string temp = num; 

            // flip bit
            if (temp[i] == '1') {
                temp[i] = '0';
            } else {
                temp[i] = '1';
            }
            for (char x : temp) {
                if (x == '1') {
                    count++;
                }
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
