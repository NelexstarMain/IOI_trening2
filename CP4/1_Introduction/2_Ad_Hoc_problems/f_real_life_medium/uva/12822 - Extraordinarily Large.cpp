#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int costs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int to_secunds(string t) {
    return (3600 * ((t[0] - '0') * 10 + (t[1] - '0')) + 
            60 * ((t[3] - '0') * 10 + (t[4] - '0')) + 
            ((t[6] - '0') * 10 + (t[7] - '0')));
}

int time_minus(string start, string end) {
    return (to_secunds(end) - to_secunds(start));
}

int get_cost(int n) {
    string s = to_string(n);
    int c = 0;
    bool f = false;
    for (char x : s) {
        if (x != '0') f = true;
        if (x == '0' && f == false) {
            continue;
        } else {
            c += costs[x - '0'];
        }
    }
    if (c == 0) return 6;
    return c;
}

int countscore(int hp, int gp) {
    return get_cost(hp) + get_cost(gp);
}

bool solve(int z) {
    string s;
    string start, time, winner;
    int points;
    int hp = 0, gp = 0;
    ll score = 0;

    while (cin >> s) {
        if (s == "START") {
            cin >> start;
            hp = 0;
            gp = 0;
            score = 0;
        } else if (s == "END") {
            cin >> time;
            score += (ll)time_minus(start, time) * countscore(hp, gp);
            cout << "Case " << z << ": " << score << "\n";
            return true;
        } else {
            cin >> time;
            cin >> winner >> points;
            score += (ll)time_minus(start, time) * countscore(hp, gp);
            if (winner == "home") {
                hp += points;
            } else {
                gp += points;
            }
            start = time;
        }
    }
    return false;
}

int main() {
    fast_io();
    int z = 1;
    while (solve(z)) z++;
    return 0;
}