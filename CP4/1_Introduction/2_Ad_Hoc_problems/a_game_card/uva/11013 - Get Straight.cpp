#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

std::unordered_map<char, int> change = {
    {'A', 0}, {'2', 1},{'3', 2},{'4', 3},{'5', 4},{'6', 5},
    {'7', 6},{'8', 7},{'9', 8},{'T', 9},  {'J', 10}, {'Q', 11}, {'K', 12}  
};
std::vector<char> allchars = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
std::vector<char> allsuits = {'S', 'H', 'D', 'C'};

double cost(std::vector<char> n) {
    std::map<char, int> a;
    for (char x: n) {
        a.push_back(change[x]);
    }
    std::vector<int> bests;
    int before = a[0];
    int best = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == before+1 || a[i] == 0 && before == 12) {
            best++;
        } else {
            bests.push_back(best);
        }
        before = a[i];
    }
    std::sort(ALL(bests));
    if (bests.size() > 1) {
        if (bests[bests.size()-1] == 4) {
            return 10.0; 
        } else if (bests[bests.size()-1] == 3 && bests[bests.size()-2] == 2) {
            return 5.0;
        } else if (bests[bests.size()-1] == 3) {
            return 3.0;
        } else if (bests[bests.size()-1] == 2 && bests[bests.size()-2] == 2) {
            return 1.0;
        } else {
            return 0.0;
        }
    } else {
        return 100.0;
    }
}

bool solve() {
    std::vector<std::string> n; 
    std::unordered_multiset<std::string> all;
    for (char y: allsuits) {
        for (char x: allchars) {
            std::string s = std::to_string(x);
            s += y;
            all.insert(s);
        }
    }
    std::string f; std::cin >> f;
    if (f[0] == '#') return false;
    n.push_back(f);
    for (int i = 1; i < 5; i++) {
        std::cin >> f;
        n.push_back(f);
        all.erase(f);
    }
    double maxcost = 0.0;
    for (std::string x: n) {
        double costsum = 0.0;
        bool found = false;
        std::vector<char> newv;
        for (std::string y: n) {
            if (y != x || found == true) {
                newv.push_back(y[0]);
            }
        }
        for (std::string z: all) {
            std::vector<char> newvector = newv;
            newvector.push_back(z[0]);
            costsum += cost(newvector);
        }
        maxcost = std::max((costsum/47.0)-2.0, maxcost);
    }
    std::vector<char> nn;
    for (std::string x: n) {
        nn.push_back(x[0]);
    }
    if (cost(nn)-1.0 > maxcost) {
        std::cout << "Stay\n";
    } else {
        std::cout << "Exchange\n";
    }
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}
