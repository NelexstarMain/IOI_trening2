#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    set<string> list;
    cin >> s;

    sort(s.begin(), s.end());  

    do {
        list.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << list.size() << "\n";

    for (const auto& perm : list) {
        cout << perm << "\n";
    }

    return 0;
}
