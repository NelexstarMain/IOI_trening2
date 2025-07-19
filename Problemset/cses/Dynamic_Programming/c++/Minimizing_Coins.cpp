#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, x;
vector<int> coins;
unordered_map<int, int> memo;

int min_coins(int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return INF;
    if (memo.count(amount)) return memo[amount];

    int ans = INF;
    for (int c : coins) {
        int res = min_coins(amount - c);
        if (res != INF) {
            ans = min(ans, res + 1);
        }
    }

    memo[amount] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    coins.resize(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int result = min_coins(x);
    if (result == INF) cout << -1 << "\n";
    else cout << result << "\n";

    return 0;
}
