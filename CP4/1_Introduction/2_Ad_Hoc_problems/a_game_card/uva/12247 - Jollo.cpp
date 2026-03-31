#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool solve() {
    int A, B, C, D, E; 
    if (!(std::cin >> A >> B >> C >> D >> E)) return false; 
    if (A == 0 && B == 0 && C == 0 && D == 0 && E == 0) return false;

    bool used[53] = {false};
    used[A] = used[B] = used[C] = used[D] = used[E] = true;

    std::vector<int> pr = {A, B, C};
    std::sort(pr.begin(), pr.end());

    for (int card = 1; card <= 52; card++) {
        if (used[card]) continue; 
        std::vector<int> p = {D, E, card};
        std::sort(p.begin(), p.end());
        if (p[1] > pr[2]) {
            std::cout << card << "\n";
            return true;
        }
        if (p[0] > pr[1]) {
            std::cout << card << "\n";
            return true;
        }
    }
    std::cout << "-1\n";
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}