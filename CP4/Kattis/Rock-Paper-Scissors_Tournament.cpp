#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

bool solve() {
    int n, k;
    cin >> n;                  
    if (n == 0) return false;
    cin >> k;                    
    
    int games = (k * n * (n - 1)) / 2;
    vector<pair<int,int>> scores(n, {0, 0});  

    for (int i = 0; i < games; i++) {
        int first, second;
        string move1, move2;
        cin >> first >> move1 >> second >> move2;  
        first--; second--;

        if (move1 == move2) continue;

        bool wins1 = (move1 == "rock" && move2 == "scissors") ||
                     (move1 == "scissors" && move2 == "paper") ||
                     (move1 == "paper" && move2 == "rock");

        if (wins1) {
            scores[first].second++;
            scores[second].first++;
        } else {
            scores[first].first++;
            scores[second].second++;
        }
    }


    cout << fixed << setprecision(3);

    for (int i = 0; i < n; i++) {
        int w = scores[i].second;
        int l = scores[i].first;
        
        if (w + l == 0) {
            cout << "-\n";
        } else {
            cout << 1.0 * w / (w + l) << "\n";   
        }
    }

    cout << "\n";  
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (solve());
    return 0;
}