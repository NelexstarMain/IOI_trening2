#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define F first
#define S second
#define PB push_back
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

std::unordered_map<int, std::string> A;
std::unordered_map<std::string, int> Ver;
std::unordered_map<int, int> Next;
std::vector<int> B;

pii change(std::string x, std::string y) {
    int xval, yval;
    if (x[0] >= 'A' && x[0] <= 'Z') xval = Ver[x];
    else xval = std::stoi(x);

    if (y[0] >= 'A' && y[0] <= 'Z') yval = Ver[y];
    else yval = std::stoi(y);
    return {xval, yval};
}

bool Con(std::string x, std::string y, std::string exp) {
    pii res = change(x, y);
    int xval = res.F, yval = res.S;
    if (exp == "<") return xval < yval;
    if (exp == "<=") return xval <= yval;
    if (exp == "=") return xval == yval;
    if (exp == ">=") return xval >= yval;
    if (exp == ">") return xval > yval;
    if (exp == "<>") return xval != yval;
    return false;
}

int Ari(std::string x, std::string y, std::string exp) {
    pii res = change(x, y);
    int xval = res.F, yval = res.S;
    if (exp == "+") return xval + yval;
    if (exp == "-") return xval - yval;
    if (exp == "*") return xval * yval;
    if (exp == "/") return xval / yval;
    return 0;
}

void solve() {
    for (char c = 'A'; c <= 'Z'; ++c) {
        Ver[string(1, c)] = 0;
    }

    std::string l; 
    while (std::getline(std::cin, l)) {
        if (l.empty()) continue;
        std::stringstream ss(l);
        int f; 
        if (!(ss >> f)) continue;
        B.PB(f); 
        A[f] = l; 
    }
    
    if (B.empty()) return;
    std::sort(ALL(B));
    
    for (int i = 0; i < SIZE(B) - 1; i++) {
        Next[B[i]] = B[i+1];
    }

    int curr = B[0];
    while (true) {
        bool jumped = false;
        std::string line = A[curr];
        std::stringstream ss(line);
        
        int label;
        std::string c; 
        ss >> label >> c;

        if (c == "LET") {
            std::string name, eq, x, exp, y;
            ss >> name >> eq >> x;
            if (ss >> exp) {
                ss >> y;
                Ver[name] = Ari(x, y, exp);
            } else {
                if (x[0] >= 'A' && x[0] <= 'Z') Ver[name] = Ver[x];
                else Ver[name] = std::stoi(x);
            }
        } 
        else if (c == "IF") {
            std::string x, exp, y, then_word, goto_word;
            int target;
            ss >> x >> exp >> y >> then_word >> goto_word >> target;
            if (Con(x, y, exp)) {
                curr = target;
                jumped = true;
            }
        } 
        else if (c == "PRINT" || c == "PRINTLN") {
            bool newline = (c == "PRINTLN");
            std::string content;
            std::getline(ss, content);
            
            if (!content.empty() && content[0] == ' ') content.erase(0, 1);

            if (!content.empty() && content[0] == '"') {
                size_t first = content.find('"');
                size_t last = content.rfind('"');
                std::cout << content.substr(first + 1, last - first - 1);
            } else {
                std::cout << Ver[content];
            }
            if (newline) std::cout << "\n";
        }

        if (!jumped) {
            if (Next.find(curr) == Next.end()) break;
            curr = Next[curr];
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}