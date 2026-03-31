#include <bits/stdc++.h>

using namespace std;

string toRoman(int n) {
    const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return tens[n / 10] + ones[n % 10];
}

void solve() {
    string s;
    cin >> s;
    map<char, int> inputCounts;
    for (char c : s) {
        inputCounts[c]++;
    }
    for (int i = 1; i < 100; ++i) {
        string r = toRoman(i);
        map<char, int> currentCounts;
        for (char c : r) {
            currentCounts[c]++;
        }
        if (inputCounts == currentCounts) {
            cout << r << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}