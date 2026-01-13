#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> cntA(101, 0), cntB(101, 0);

    while (N--) {
        int a, b; cin >> a >> b;
        cntA[a]++;
        cntB[b]++;
        vector<int> tmpA = cntA;
        vector<int> tmpB = cntB;

        int i = 1, j = 100;
        int max_sum = 0;
        while (i <= 100 && j >= 1) {
            if (tmpA[i] == 0) { i++; continue; }
            if (tmpB[j] == 0) { j--; continue; }

            max_sum = max(max_sum, i + j);

            int take = min(tmpA[i], tmpB[j]);
            tmpA[i] -= take;
            tmpB[j] -= take;
        }
        cout << max_sum << "\n";
    }
    return 0;
}