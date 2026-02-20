#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Car { // Klasa modelu auta
    ll CP, PC, KC;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // wczytujemy modele aut
    map<string, Car> cars;
    for (int i = 0; i < n; i++) {
        string name;
        ll p, q, k;
        cin >> name >> k >> p >> q;
        cars[name] = {k, p, q};
    }

    map<string, ll> C; // ile musi zapłacić agent
    map<string, string> CC; // auta przypisane do agenta
    map<string, bool> I; // czy jest poprawny
    set<string> S; // zbiór agentów bez powtórek

    for (int i = 0; i < m; i++) {
        int t; std::string sname, action; std::cin >> t >> sname >> action;
        S.insert(sname); // dodajemy agenta 

        if (action == "p") {
            string cname; cin >> cname; // nazwa auta
            if (I[sname]) continue; // jesli już niejest poprawny to go pomijamy
            if (CC.count(sname)) I[sname] = true; // jesli ma auto to dajemy że jest niepoprawny, niemoże miec dwuch aut na raz
            else { // Poprawnie
                CC[sname] = cname; // dajemy mu auto
                C[sname] += cars[cname].PC; // płaci cene wynajmu
            }
        } 
        else if (action == "r") { // Oddaje
            ll dist; cin >> dist;
            if (I[sname]) continue;
            if (!CC.count(sname)) I[sname] = true;
            else {
                string cname = CC[sname];
                C[sname] += dist * cars[cname].KC; CC.erase(sname); // naliczamy mu za kazdy kilometr i zabieramy auto
            }
        } 
        else if (action == "a") {
            ll severity; cin >> severity;
            if (I[sname]) continue;
            if (!CC.count(sname)) I[sname] = true; 
            else {
                string cname = CC[sname];
                ll repair = (severity * cars[cname].CP + 99) / 100; C[sname] += repair; // odliczamy ile trzeba za naprawe auta 
            }
        }
    }

    for (const string& spy : S) { // sprawdzamy czy wszyscy oddali pod koniec roku
        if (CC.count(spy)) I[spy] = true;
        std::cout << spy << " ";
        if (I[spy]) cout << "INCONSISTENT" << "\n";
        else cout << C[spy] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}