#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    while (cin >> L && L != 0) {
        vector<string> bends(L - 1);
        for (int i = 0; i < L - 1; i++) cin >> bends[i];

        string dir = "+x";

        for (auto &bend : bends) {
            if (bend == "No") continue;

            if (dir == "+x") dir = bend;
            else if (dir == "-x") {
                dir = (bend[0] == '+') ? "-" + bend.substr(1) : "+" + bend.substr(1);
            }
            else if (dir == "+y") {
                if (bend == "+y") dir = "-x";
                else if (bend == "-y") dir = "+x";
            }
            else if (dir == "-y") {
                if (bend == "+y") dir = "+x";
                else if (bend == "-y") dir = "-x";
            }
            else if (dir == "+z") {
                if (bend == "+z") dir = "-x";
                else if (bend == "-z") dir = "+x";
            }
            else if (dir == "-z") {
                if (bend == "+z") dir = "+x";
                else if (bend == "-z") dir = "-x";
            }
        }

        cout << dir << '\n';
    }
    return 0;
}
