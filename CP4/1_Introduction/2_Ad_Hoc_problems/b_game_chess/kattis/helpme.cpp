#include <bits/stdc++.h>

using namespace std;

using vpii = std::vector<std::pair<int, int>>;
using pii = std::pair<int, int>;
#define all(x) x.begin(), x.end()

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    vpii wK, wQ, wR, wB, wN, wP;
    vpii bK, bQ, bR, bB, bN, bP;
    for (int i = 0; i < 8; i++) {
        std::string s, t;
        std::cin >> s >> t;
        int index = 2;
        for (int j = 0; j < 8; j++) {
            char a = t[index];
            if (a == 'K') wK.push_back({8-i, j+1});
            else if (a == 'Q') wQ.push_back({8-i, j+1});
            else if (a == 'R') wR.push_back({8-i, j+1});
            else if (a == 'B') wB.push_back({8-i, j+1});
            else if (a == 'N') wN.push_back({8-i, j+1});
            else if (a == 'P') wP.push_back({8-i, j+1});
            else if (a == 'k') bK.push_back({8-i, j+1});
            else if (a == 'q') bQ.push_back({8-i, j+1});
            else if (a == 'r') bR.push_back({8-i, j+1});
            else if (a == 'b') bB.push_back({8-i, j+1});
            else if (a == 'n') bN.push_back({8-i, j+1});
            else if (a == 'p') bP.push_back({8-i, j+1});
            index += 4;
        }
    }
    std::string end; std:cout << end;
    auto wsort = [](pii a, pii b) {
        if (a.first != b.first) {
            return a.first < b.first; 
        } else {
            return a.second < b.second;
        }
    };
    auto bsort = [](pii a, pii b) {
        if (a.first != b.first) {
            return a.first > b.first; 
        } else {
            return a.second < b.second;
        }
    };
    sort(all(wK), wsort);
    sort(all(wQ), wsort);
    sort(all(wR), wsort);
    sort(all(wB), wsort);
    sort(all(wN), wsort);
    sort(all(wP), wsort);

    sort(all(bK), bsort);
    sort(all(bQ), bsort);
    sort(all(bR), bsort);
    sort(all(bB), bsort);
    sort(all(bN), bsort);
    sort(all(bP), bsort);

   
    
    cout << "White: ";
    bool first = true;
    for (auto x: wK) { if (!first) cout << ","; cout << "K" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: wQ) { if (!first) cout << ","; cout << "Q" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: wR) { if (!first) cout << ","; cout << "R" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: wB) { if (!first) cout << ","; cout << "B" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: wN) { if (!first) cout << ","; cout << "N" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: wP) { if (!first) cout << ","; cout << (char)('a'+(x.second-1)) << x.first; first = false; }
    cout << "\n";

    cout << "Black: ";
    first = true;
    for (auto x: bK) { if (!first) cout << ","; cout << "K" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: bQ) { if (!first) cout << ","; cout << "Q" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: bR) { if (!first) cout << ","; cout << "R" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: bB) { if (!first) cout << ","; cout << "B" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: bN) { if (!first) cout << ","; cout << "N" << (char)('a'+(x.second-1)) << x.first; first = false; }
    for (auto x: bP) { if (!first) cout << ","; cout << (char)('a'+(x.second-1)) << x.first; first = false; }
    cout << "\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}
