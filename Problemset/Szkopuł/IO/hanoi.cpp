#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> all_data;
    vector<int> starts(m, 0);     
    vector<int> element_count(m, 0);

    bool zeros = false;
    int zeros_index = -1;
    int non_empty_count = 0;
    
    int current_data_offset = 0; 
    
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (k == 0) {
            zeros = true;
            zeros_index = i;
        } else {
            non_empty_count++;
            starts[i] = current_data_offset;
            element_count[i] = k;
            current_data_offset += k;
            
            for (int j = 0; j < k; ++j) { 
                int x; cin >> x;
                all_data.push_back(x); 
            }
        }
    }

    if (non_empty_count <= 1 && zeros) {
        cout << "0\n";
        return;
    }

    int lowest_pick = INF, lowest_pick_index = -1, secondlowest = INF;

    for (int i = 0; i < m; i++) {
        if (element_count[i] > 0) {
            int first_val = all_data[starts[i]];
            if (first_val < lowest_pick ) {
                secondlowest = lowest_pick;
                lowest_pick = first_val;
                lowest_pick_index = i;
            } else if (first_val < secondlowest) {
                secondlowest = first_val;
            }
        }
    }

    int lowerhighest = INF;
    if (lowest_pick_index != -1 && element_count[lowest_pick_index] > 0) {
        lowerhighest = all_data[starts[lowest_pick_index] + element_count[lowest_pick_index] - 1];
    }

    vector<pii> moves;
    if (lowerhighest > secondlowest && !zeros) {
        cout << "-1\n";
        return;
    } else {
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> minHeap;
        vector<int> processed_count(m, 0); 
        bool used = false;
        if (lowerhighest > secondlowest && zeros) {
            moves.PB({lowest_pick_index + 1, zeros_index + 1});
            processed_count[lowest_pick_index]++; 
        } else {
            zeros_index = lowest_pick_index;
            used = true;
        }

        for (int i = 0; i < m; i++) {
            if (element_count[i] > 0 && processed_count[i] < element_count[i]) {
                if (used && i == zeros_index) {
                    continue;
                }
                int current_j = processed_count[i];
                int val = all_data[starts[i] + current_j];
                minHeap.push({val, {i, current_j}});
            }
        }

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            
            int idx_a = top.second.first;
            int idx_j = top.second.second;
            if (idx_j != processed_count[idx_a]) {
                continue; 
            }
            
            moves.PB({idx_a + 1, zeros_index + 1});
            processed_count[idx_a]++; 

            int next_j = processed_count[idx_a];

            if (next_j < element_count[idx_a]) {
                int next_val = all_data[starts[idx_a] + next_j];
                minHeap.push({next_val, {idx_a, next_j}});
            }
        }
        
        std::cout << SIZE(moves) << "\n";
        for (auto move : moves) {
            std::cout << move.F << " " << move.S << "\n";
        }
    }
}
int main() {
    fast_io();
    solve();
    return 0;
}