#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int caseNum) {
    vector<int> f1(10001, 0), f2(10001, 0), f3(10001, 0);

    auto readInput = [](vector<int>& f) {
        int s, id;
        if (!(cin >> s)) return;
        for (int i = 0; i < s; ++i) {
            cin >> id;
            if (id >= 1 && id <= 10000) f[id] = 1;
        }
    };

    readInput(f1);
    readInput(f2);
    readInput(f3);

    vector<int> u1, u2, u3;
    for (int i = 1; i <= 10000; ++i) {
        if (f1[i] == 1 && f2[i] == 0 && f3[i] == 0) u1.push_back(i);
        if (f2[i] == 1 && f1[i] == 0 && f3[i] == 0) u2.push_back(i);
        if (f3[i] == 1 && f1[i] == 0 && f2[i] == 0) u3.push_back(i);
    }

    int m = max({(int)u1.size(), (int)u2.size(), (int)u3.size()});

    cout << "Case #" << caseNum << ":" << endl;

    auto printResult = [](int id, const vector<int>& unique) {
        cout << id << " " << unique.size();
        for (int prob : unique) {
            cout << " " << prob;
        }
        cout << "\n";
    };

    if (u1.size() == m) printResult(1, u1);
    if (u2.size() == m) printResult(2, u2);
    if (u3.size() == m) printResult(3, u3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}