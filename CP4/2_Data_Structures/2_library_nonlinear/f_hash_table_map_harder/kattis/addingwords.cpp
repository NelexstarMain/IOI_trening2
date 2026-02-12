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

void solve() {
    std::string l;
    std::unordered_map<std::string, int> A; std::unordered_map<int, std::string> B;
    while (std::getline(std::cin, l)) {
        std::stringstream ss(l);
        std::string curr; ss >> curr;  
        if (curr == "def") {
            std::string name; int num; 
            ss >> name >> num;
            if (A.find(name) != A.end()) B.erase(A[name]);
            A[name] = num; B[num] = name;
            // for (auto [k, v]: A) std::cout << k << " " << v << "\n";
            // for (auto [k, v]: B) std::cout << k << " " << v << "\n";
            // std::cout << "\n";

        } else if (curr == "calc") {
            std::string s, f;
            int sum = 0;
            bool prev = true, valid = true;
            do {
                ss >> s >> f;
                std::cout << s << " " << f << " ";
                if (prev) {
                    if (A.find(s) != A.end()) sum += A[s];
                    else valid = false;
                } else {
                    if (A.find(s) != A.end()) sum -= A[s];
                    else valid = false;
                }
                prev = (f == "+") ? true : false;
            } while (f != "=");
            // std::cout << sum << "\n";
            if (B.find(sum) != B.end() && valid) std::cout << B[sum] << "\n";
            else std::cout << "unknown\n";

        } else if (curr == "clear") { A.clear(); B.clear(); }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
