#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    const int N = 1e5 + 5;
    vector<int> to(N, -1);        
    vector<int> cap(N, 0);        
    vector<bool> has_in(N, false); 
    vector<bool> has_out(N, false); 

    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        to[a] = b;
        cap[a] = d;
        has_in[b] = true;
        has_out[a] = true;
    }

    vector<tuple<int, int, int>> result;

    for (int i = 1; i <= n; i++) {

        if (!has_in[i] && has_out[i]) {
            int curr = i;
            int min_cap = 1e9;
            while (to[curr] != -1) {
                min_cap = min(min_cap, cap[curr]);
                curr = to[curr];
            }
            result.emplace_back(i, curr, min_cap);
        }
    }

    cout << result.size() << "\n";
    for (auto [start, end, min_c] : result) {
        cout << start << " " << end << " " << min_c << "\n";
    }
}
