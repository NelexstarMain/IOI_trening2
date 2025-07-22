#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    
    int tests;

    std::cin >> tests;

    for (int i = 0; i<tests; i++) {
        int n;
        std::cin >> n;
        std::set<int> found;
        for (int i = 0; i<n; i++) {
            int a;
            std::cin >> a;
            found.insert(a);
        }
        std::cout << found.size() << std::endl;

    }


}