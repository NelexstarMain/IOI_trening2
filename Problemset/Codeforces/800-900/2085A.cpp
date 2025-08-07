#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void solve() {
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    
    std::string reversed_s = s; std::reverse(reversed_s.begin(), reversed_s.end());
    
    if (s < reversed_s) std::cout << "YES\n";
    else if (k >= 1) {
        bool all_same = true;
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] != s[0]) {
                all_same = false;
                break;
            }
        }
        if (!all_same) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n, m;
    // cin >> n >> m;

    
    return 0;
}#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n, m;
    // cin >> n >> m;

    
    return 0;
}

