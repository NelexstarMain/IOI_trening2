#include <bits/stdc++.h>

using namespace std;

struct Record {
    string re, ti, ac;
    int km, total_min, hour;
    bool operator<(const Record& o) const {
        if (re != o.re) return re < o.re;
        return total_min < o.total_min;
    }
};

void solve(bool first) {
    vector<int> a(24); 
    for (int &x : a) cin >> x;
    
    cin.ignore();
    string l;
    vector<Record> records;

    while (getline(cin, l) && !l.empty()) {
        stringstream ss(l); 
        string re, ti, ac;
        int km;
        ss >> re >> ti >> ac >> km;
        int d = stoi(ti.substr(3, 2));
        int h = stoi(ti.substr(6, 2));
        int m = stoi(ti.substr(9, 2));
        int total_min = d * 1440 + h * 60 + m;

        records.push_back({re, ti, ac, km, total_min, h});
    }

    sort(records.begin(), records.end());

    map<string, int> P; 
    for (int i = 0; i < (int)records.size() - 1; ++i) {
        if (records[i].re == records[i+1].re && 
            records[i].ac == "enter" && 
            records[i+1].ac == "exit") {
            
            int dist = abs(records[i+1].km - records[i].km);
            int trip_cost = dist * a[records[i].hour] + 100;
            P[records[i].re] += trip_cost;
        }
    }

    if (!first) cout << "\n";

    for (auto const& [k, v] : P) {
        int total = v + 200;
        printf("%s $%.2f\n", k.c_str(), total / 100.0);
    }
}

int main() {
    int T; 
    if (!(cin >> T)) return 0;
    for (int i = 0; i < T; ++i) {
        solve(i == 0);
    }
    return 0;
}