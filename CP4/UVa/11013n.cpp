#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define ALL(a) (a).begin(), (a).end()

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


std::unordered_map<char, int> reverse_change = {
    {'A', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7}, 
    {'9', 8}, 
    {'T', 9},
    {'J', 10},
    {'Q', 11},
    {'K', 12}
};

std::vector<char> allchars = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
std::vector<char> allsuits = {'S', 'H', 'D', 'C'};

int cost(std::vector<char> a) {
    int count[13] = {0};
    for (char x: a) {
        count[reverse_change[x]]++;
    }
    int best1 = 0, bindex = 0;
    int curr = 0;
    for (int i = 0; i <= 17; i++) {
        if (count[i%13] > 0) {
            curr++;
            if (curr > best1) {
                best1 = curr;
                bindex = i;
            }
        } else {
            curr = 0;
        }
    }
    for (int i = 0; i < best1; i++) {
        count[bindex%13]--;
        bindex = (bindex + 12) % 13;
    }
    int best2 = 0;
    curr = 0;
    for (int i = 0; i <= 17; i++) {
        if (count[i%13] > 0) {
            curr++;
            if (curr > best2) {
                best2 = curr;
            }
        } else {
            curr = 0;
        }
    }
    if (best1 == 5) return 100;
    else if (best1 == 4) return 10;
    else if (best1 == 3 && best2 == 2) return 5;
    else if (best1 == 3) return 3;
    else if (best1 == 2 && best2 == 2) return 1;
    return 0;
}

bool solve() {
    std::unordered_set<std::string> j;
    std::vector<std::string> z;
    std::string a, b, c, d, e; 
    std::cin >> a;
    if (a == "#") return false;
    std::cin >> b >> c >> d >> e;
    z = {a, b, c, d, e};

    for (char x: allchars) {
        for (char y: allsuits) {
            std::string res = "";
            res += x;
            res += y;
            if (std::find(ALL(z), res) == z.end()) j.insert(res);
        }
    }
    std::vector<ll> costs;
    for (auto x: z) {
        std::vector<char> newv;
        ll allcost = 0;
        for (auto y: z) {
            if (y != x) {
                newv.push_back(y[0]);
            }
        }
        for (auto f: j) {
            std::vector<char> newvc = newv;
            newvc.push_back(f[0]);
            allcost += cost(newvc)-2;
        }
        costs.push_back(allcost);
    }
    

    ll maximum = -1000000000; 
    int index = -1;
    
    for (int i = 0; i < 5; i++) {
        if (costs[i] > maximum) {
            maximum = costs[i];
            index = i;
        }
    }
    
    std::vector<char> al;
    for (auto x: z) al.push_back(x[0]);

    ll singleCost = 47LL * (cost(al)-1);
    
    if (singleCost >= maximum) {
        std::cout << "Stay\n";
    } else {
        std::cout << "Exchange " << z[index] << "\n";
    }
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}