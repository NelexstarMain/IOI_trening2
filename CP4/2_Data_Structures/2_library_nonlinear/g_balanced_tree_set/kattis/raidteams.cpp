#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Object {
    string name;
    int s[3]; 
    bool used = false; 
};

struct Comp {
    int id;
    bool operator()(const Object* lhs, const Object* rhs) const {
        if (lhs->s[id] != rhs->s[id]) 
            return lhs->s[id] > rhs->s[id]; 
        return lhs->name < rhs->name;       
    }
};

void solve() {
    int n; cin >> n;
    vector<Object> players(n);
    set<Object*, Comp> skills[3] = { 
        set<Object*, Comp>(Comp{0}), 
        set<Object*, Comp>(Comp{1}), 
        set<Object*, Comp>(Comp{2}) 
    };

    for (int i = 0; i < n; i++) {
        cin >> players[i].name >> players[i].s[0] >> players[i].s[1] >> players[i].s[2];
        for (int j = 0; j < 3; j++) {
            skills[j].insert(&players[i]);
        }
    }

    while (true) {
        vector<Object*> current_team;

        for (int j = 0; j < 3; j++) {
            while (!skills[j].empty() && (*skills[j].begin())->used) {
                skills[j].erase(skills[j].begin());
            }

            if (skills[j].empty()) goto end_loop; 

            Object* best = *skills[j].begin();
            best->used = true; 
            current_team.push_back(best);
            skills[j].erase(skills[j].begin());
        }

        vector<string> names;
        for (auto p : current_team) names.push_back(p->name);
        sort(names.begin(), names.end());

        cout << names[0] << " " << names[1] << " " << names[2] << "\n";
    }
    end_loop:;
}

int main() {
    fast_io();
    solve();
    return 0;
}