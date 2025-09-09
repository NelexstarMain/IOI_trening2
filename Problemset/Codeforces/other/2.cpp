#include <iostream>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    map<char, int> counter;
    for (char x : s) counter[x]++;

    char minChar = s[0], maxChar = s[0];
    for (auto &p : counter) {
        if (p.second < counter[minChar]) minChar = p.first;
        if (p.second > counter[maxChar]) maxChar = p.first;
    }

    if (minChar == maxChar) {
        for (auto &p : counter) {
            if (p.first != minChar) {
                maxChar = p.first;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == minChar) {
            s[i] = maxChar;
            break;
        }
    }

    cout << s << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
