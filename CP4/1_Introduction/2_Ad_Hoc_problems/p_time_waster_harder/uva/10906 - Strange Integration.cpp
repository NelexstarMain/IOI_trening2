#include <bits/stdc++.h>

using namespace std;

int main() {


    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        map<string, pair<char, string>> variables;
        int m;
        cin >> m;
        string varC, varA, varB, tmp;
        char op;
        while (m--) {
            cin >> varC >> tmp >> varA >> op >> varB;
            string expr;
            if (variables.count(varA)) {
                if (variables[varA].first == '+' && op == '*') {
                    expr += '(' + variables[varA].second + ')';
                } else {
                    expr += variables[varA].second;
                }
            } else {
                expr += varA;
                variables[varA] = {'$', varA};
            }
            expr += op;
            if (variables.count(varB)) {
                if (variables[varB].first == '*' && op == '+' || variables[varB].first == '$') {
                    expr += variables[varB].second;
                } else {
                    expr += '(' + variables[varB].second + ')';
                }
            } else {
                expr += varB;
                variables[varB] = {'$', varB};
            }
            variables[varC] = {op, expr};
        }
        cout << "Expression #" << i << ": " << variables[varC].second << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}