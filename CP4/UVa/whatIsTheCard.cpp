#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(int z) {
    
    std::vector<std::string> a(52); 
    
    for (int i = 0; i < 52; i++) {
        std::string x;
        std::cin >> x; 
        a[i] = x;
        

    }
    std::reverse(a.begin(), a.end());
    std::vector<std::string> newv;
    auto it = a.begin();
    for (int i = 0; i < 25; i++) {
        newv.push_back(*it);
        it = a.erase(it);

    }
    int index = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        char c = a[index][0];
        int x = (c >= '2' && c <= '9') ? c - '0' : 10;
        y += x;
        a.erase(a.begin(), a.begin() + 11 - x);
    }
    newv.insert(newv.end(), a.begin(), a.end());
    std::cout << "Case " << z << ": " << newv[newv.size()-y] << "\n";
}

int main() {
    fast_io();
    int t; 
    
    if (!(std::cin >> t)) return 0; 
    int z = 1;
    while (t--) {
        solve(z);
        z++;
    }
    return 0;
}