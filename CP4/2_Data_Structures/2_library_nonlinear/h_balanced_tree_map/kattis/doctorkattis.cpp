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
struct CatEntry {
    int il, at; string name; // Parametry
    bool operator<(const CatEntry& other) const { // Comperator zdefiniowany najpierw rosnąco po wspułczyniku choroby potem malejąco po kolejnosci przyjscia
        if (il != other.il) return il < other.il; 
        return at > other.at;
    }
};

void solve() {
    int n;
    if (!(std::cin >> n)) return;
    std::priority_queue<CatEntry> pq; // posortowana kolejnosc klass
    std::unordered_map<string, int> til; // przypisane wartiscu do kazdego elementu najnowszy stan
    std::unordered_map<string, int> ats; // data przyjscia

    for (int i = 0; i < n; i++) {
        int type; // jakie zadanie
        std::cin >> type;

        if (type == 0) { // przyjezdza klijent
            std::string name; int level;
            std::cin >> name >> level;
            til[name] = level; ats[name] = i; // zapisuje
            pq.push({level, i, name}); // wrzuca

        } else if (type == 1) { // zmiana
            std::string name; int increase;
            std::cin >> name >> increase;
            if (til.count(name)) { til[name] += increase; pq.push({til[name], ats[name], name}); } // Zabespiecznie - dodajemy warotsc i wrzucamy nowom do kolejski

        } else if (type == 2) { std::string name; cin >> name; til.erase(name); } // usuwamy z til wiec tak jakby niebyło bo wczesniej sprawdzamy
        else if (type == 3) { // mamy dac najwiekszy
            while (true) {
                if (pq.empty()) { // jesli nikogo niema w kolejce
                    std::cout << "The clinic is empty\n"; break;
                }

                CatEntry top = pq.top(); // najwiekszy
                if (til.find(top.name) == til.end() || til[top.name] != top.il) pq.pop(); // jesli jest to niepoprawny wuzamy go i szukamy dalej oczyszczamy ze starych
                else { std::cout << top.name << "\n"; break; } // znalezliscmy kończymy petle
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}