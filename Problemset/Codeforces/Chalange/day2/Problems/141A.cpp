#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, int> dict;

    string a, b, d;
    cin >> a >> b >> d;

    string c = a + b;

    for (char x : c) {
        dict[x]++;
    }

    for (char x : d) {
        if (dict.find(x) != dict.end()) {
            dict[x]--;
            if (dict[x] == 0) {
                dict.erase(x);
            }
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    if (dict.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
