#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, splay_tree_tag,tree_order_statistics_node_update>

int lucky_numbers[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ordered_set lucky;
    for (int i = 1; i < 2000001; i += 2) {
        lucky.insert(i);
    }
    for (ordered_set::iterator it = ++lucky.begin(); it != lucky.end(); ++it) {
        int strike = *it;
        if (strike > lucky.size()) break;
        for (int j = strike - 1; j < lucky.size(); j += strike - 1) {
            lucky.erase(lucky.find_by_order(j));
        }
    }
    for (auto it = lucky.begin(); it != lucky.end(); ++it) {
        lucky_numbers[*it] = 1;
    }
    int n;
    while (cin >> n) {
        if (n & 1) {
            cout << n << " is not the sum of two luckies!" << endl;
            continue;
        }
        int L1 = -1, L2 = -1;
        for (int i = n / 2; i >= 1; --i) {
            if (lucky_numbers[i] && lucky_numbers[n - i]) {
                L1 = i;
                L2 = n - i;
                break;
            }
        }
        if (L1 == -1) {
            cout << n << " is not the sum of two luckies!" << endl;
        } else {
            cout << n << " is the sum of " << L1 << " and " << L2 << "." << endl;
        }
    }




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}