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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

std::unordered_map<std::string, int> notes_to_int = {
    {"C", 0}, {"C#", 1}, {"D", 2}, {"D#", 3}, {"E", 4}, {"F", 5}, 
    {"F#", 6}, {"G", 7}, {"G#", 8}, {"A", 9}, {"A#", 10}, {"B", 11}
};
std::unordered_map<int, std::string> int_to_notes = {
    {0, "C"}, {1, "C#"}, {2, "D"}, {3, "D#"}, {4, "E"}, {5, "F"}, 
    {6, "F#"}, {7, "G"}, {8, "G#"}, {9, "A"}, {10, "A#"}, {11, "B"}
};

std::vector<std::vector<int>> scales; 

void prework() {
    int pattern[] = {2, 2, 1, 2, 2, 2, 1};
    for (int i = 0; i < 12; i++) {
        int j = i;
        std::vector<int> scale = {j};
        for (int x: pattern) {
            j = (j+x)%12;
            scale.PB(j);
        }
        scales.PB(scale);
    }
}

bool solve() {
    std::string line;
    
    if (!std::getline(std::cin, line)) {
        return false;
    }
    while (!line.empty() && std::isspace(line.back())) {
        line.pop_back();
    }
    if (line.empty()) {
        return true;
    }

    if (line == "END") {
        return false;
    }
    
    std::unordered_set<int> uniq_notes;
    std::stringstream ss(line);
    std::string note;
    
    std::vector<bool> used(12, true); 
    
    while (ss >> note) uniq_notes.insert(notes_to_int[note]); 
    
    for (int i = 0; i < 12; i++) { 
        if (used[i]) {
            for (int ns : uniq_notes) {
                if (std::find(ALL(scales[i]), ns) == scales[i].end()) {
                    used[i] = false;
                    break; 
                }
            }
        }
    } 
    
    bool first = true;
    for (int i = 0; i < 12; i++) {
        if (used[i]) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << int_to_notes[i]; 
            first = false;
        }
    }
    std::cout << "\n";

    return true;
}

int main() {
    prework();
    fast_io();
    while (solve()); 
    return 0;
}