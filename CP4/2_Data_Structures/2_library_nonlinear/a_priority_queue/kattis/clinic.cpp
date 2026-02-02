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


void solve() {
    ll t, k; std::cin >> t >> k;
    std::priority_queue<std::pair<ll, std::string>> A;
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
                while (!B[A.top().S]) {
                    A.pop();
                }
                int limit = A.top().F;
                std::vector<std::pair<int, std::string>> V;
                while (!A.empty() && A.top().F == limit) {
                    if (B[A.top().S]) V.PB(A.top());
                    A.pop();
                }

                std::sort(ALL(V), [](auto& a, auto& b) {
                    return a.S < b.S;
                });
                
                B[V[0].S] = false;

                for (int i = 1; i < SIZE(V); i++) A.push(V[i]);

                std::cout << V[0].S << "\n";
                
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
