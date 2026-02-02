#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int currentSum;
    while (cin >> k) {
        vector<int> lineAbove(k), lineBelow(k);
        // get first line
        for (int i = 0; i < k; i++) {
            cin >> lineAbove[i];
        }
        for (int i = 0; i < k - 1; ++i) {
            priority_queue<int> sums;
            for (int j = 0; j < k; ++j) {
                cin >> lineBelow[j];
            }
            sort(lineBelow.begin(), lineBelow.end());
            // calculate sums and push to heap
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l < k; ++l) {
                    currentSum = lineAbove[j] + lineBelow[l];
                    if (sums.size() < k) {
                        sums.push(currentSum);
                    } else if (currentSum < sums.top()) {
                        sums.pop();
                        sums.push(currentSum);
                    } else {
                        break;
                    }
                }
            }
            for (int j = k - 1; j >= 0; --j) {
                lineAbove[j] = sums.top();
                sums.pop();
            }
        }

        for (int i = 0; i < k - 1; ++i) {
            cout << lineAbove[i] << " ";
        }
        cout << lineAbove[k - 1] << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}