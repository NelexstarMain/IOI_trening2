#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int,int> counter;
    set<int> keys;     
    vector<int> a(n), res;

    for (int &x : a) {
        cin >> x;
        counter[x]++;
        keys.insert(x);
    }

    for (int x : a) {
        int smallest = *keys.begin();

        if (x == smallest) {
            res.push_back(x);
        } else {
            res.push_back(x + 1);
            counter[x + 1]++;
            keys.insert(x + 1);
        }

        counter[x]--;
        if (counter[x] == 0)
            keys.erase(x);
    }
    std::sort(res.begin(), res.end());
    for (int x: res) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
