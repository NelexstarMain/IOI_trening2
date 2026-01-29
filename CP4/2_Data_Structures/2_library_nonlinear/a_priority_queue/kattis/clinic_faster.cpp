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

// 5 1
// 1 10 Alice 5
// 1 15 Bob 15
// 2 20
// 2 25
// 2 30

struct Patient {
    ll score; std::string name;

    bool operator<(const Patient& b) const {
        if (score != b.score) return score < b.score; 
        return name > b.name; 
    }
};

void solve() {
    ll t, k; std::cin >> t >> k;
    std::priority_queue<Patient> A;
    std::unordered_map<std::string, bool> B;
    for (int i = 0; i < t; i++) {
        int s; std::cin >> s;
        if (s == 1) {
            ll time, v; std::string name;
            std::cin >> time >> name >> v;
            ll cos = time*k;
            A.push({v-cos, name});
            B.insert({name, true});
        } else if (s == 2) {
            ll time; std::cin >> time;
            if (!A.empty()) {
                while (!B[A.top().name]) {
                    A.pop();
                }
                std::cout << A.top().name << "\n";
                A.pop();
                
            } else {
                std::cout << "doctor takes a break\n";
            }
            
        } else {
            ll time; std::cin >> time;
            std::string name; std::cin >> name;

            B[name] = false;
        }
        
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
