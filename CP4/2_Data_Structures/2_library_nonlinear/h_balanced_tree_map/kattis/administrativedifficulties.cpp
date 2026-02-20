#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Car {
    ll CP, PC, KC;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    map<string, Car> cars;
    for (int i = 0; i < n; i++) {
        string name;
        ll p, q, k;
        cin >> name >> k >> p >> q;
        cars[name] = {k, p, q};
    }

    map<string, ll> C;
    map<string, string> CC; 
    map<string, bool> I;
    set<string> S;

    for (int i = 0; i < m; i++) {
        int t; std::string sname, action; std::cin >> t >> sname >> action;
        S.insert(sname);

        if (action == "p") {
            string cname; cin >> cname;
            if (I[sname]) continue;
            if (CC.count(sname)) I[sname] = true;
            else {
                CC[sname] = cname;
                C[sname] += cars[cname].PC;
            }
        } 
        else if (action == "r") {
            ll dist; cin >> dist;
            if (I[sname]) continue;
            if (!CC.count(sname)) I[sname] = true;
            else {
                string cname = CC[sname];
                C[sname] += dist * cars[cname].KC; CC.erase(sname);
            }
        } 
        else if (action == "a") {
            ll severity; cin >> severity;
            if (I[sname]) continue;
            if (!CC.count(sname)) I[sname] = true;
            else {
                string cname = CC[sname];
                ll repair = (severity * cars[cname].CP + 99) / 100; C[sname] += repair;
            }
        }
    }

    for (const string& spy : S) {
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