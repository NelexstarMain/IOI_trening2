#include <bits/stdc++.h>

using namespace std;

const vector<pair<string, int>> roman = {
        {"M",  1000},
        {"CM", 900},
        {"D",  500},
        {"CD", 400},
        {"C",  100},
        {"XC", 90},
        {"L",  50},
        {"XL", 40},
        {"X",  10},
        {"IX", 9},
        {"V",  5},
        {"IV", 4},
        {"I",  1}
};

const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

int romanToDecimal(string s) {
    if (!regex_match(s, pattern)) return 10000;
    int ans = 0;
    for (int i = 0; i < roman.size(); ++i) {
        while (s.substr(0, roman[i].first.size()) == roman[i].first) {
            ans += roman[i].second;
            s = s.substr(roman[i].first.size());
        }
    }
    return ans;
}

string decimalToRoman(int n) {
    string ans;
    for (int i = 0; i < roman.size(); ++i) {
        while (n >= roman[i].second) {
            ans += roman[i].first;
            n -= roman[i].second;
        }
    }
    return ans;
}


int main() {

    vector<string> roman1000;
    for (int i = 1; i <= 1000; ++i) {
        roman1000.push_back(decimalToRoman(i));
    }
    sort(roman1000.begin(), roman1000.end());
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int x1000r = x % 1000, x1000q = x / 1000;
        if (x1000r == 0) x1000r = 1000, x1000q--;

        string xInRoman = decimalToRoman(x1000r);
        int pos = static_cast<int>(find(roman1000.begin(), roman1000.end(), xInRoman) - roman1000.begin()) + 1;
        if (pos > 946) pos = pos - 1000 - 1;

        if (x <= 1000) {
            cout << pos << endl;
        } else { 
            if (pos>0) cout << pos + x1000q * 946 << endl;
            else cout << pos + x1000q * -54 << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}