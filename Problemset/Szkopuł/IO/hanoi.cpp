#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using di = deque<int>; 

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


struct VectorComparator {
    bool operator()(const pair<di, int>& a, const pair<di, int>& b) const {
        return a.first[0] > b.first[0]; 
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<di> a(m); 
    bool zeros = false;
    int zeros_index = -1;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (k == 0) {
            zeros = true;
            zeros_index = i;
        } else {
            di v; 
            for (int j = 0; j < k; ++j) { 
                int x; cin >> x;
                v.push_back(x); 
            }
            a[i] = v; 
        }
    }



    int lowest_pick = INF, lowest_pick_index = -1, secondlowest = INF;

    for (int i = 0; i < m; i++) {
            if (!a[i].empty()) {
                if (a[i][0] < lowest_pick ) {
                secondlowest = lowest_pick;
                lowest_pick = a[i][0];
                lowest_pick_index = i;
                } else if (a[i][0] < secondlowest) {
                    secondlowest = a[i][0];
                }
            }
            
        }

        int lowerhighest = INF;
        if (!a[lowest_pick_index].empty()) {
            lowerhighest = a[lowest_pick_index].back();
        }

    vector<pii> moves;
    if (lowerhighest > secondlowest && !zeros) {
        cout << "-1\n";
        return;
    } else {

        priority_queue<pair<di, int>, vector<pair<di, int>>, VectorComparator> minHeap;
        priority_queue<pii, vector<pii>, greater<pii>> singleHeap;
        
        if (lowerhighest > secondlowest && zeros) {
            moves.PB({lowest_pick_index + 1, zeros_index + 1});
            a[lowest_pick_index].pop_front();
            

        }


        for (int i = 0; i < m; i++) {
            if (!a[i].empty() && a[i].size() > 1) {
                minHeap.push({a[i], i});
            } else if (!a[i].empty() && a[i].size() == 1) {
                singleHeap.push({a[i][0], i});
            }
        }

        while (!minHeap.empty() || !singleHeap.empty()) {
            if (singleHeap.empty()) {
                auto top = minHeap.top();
                di vec = top.first; 
                int idx = top.second;        
                minHeap.pop();

                moves.PB({idx + 1, zeros_index + 1});

                vec.pop_front();
                if (!vec.empty()) minHeap.push({vec, idx});
            } else if (minHeap.empty()) {
                auto top = singleHeap.top();
                int val = top.first; 
                int idx = top.second;        
                singleHeap.pop();

                moves.PB({idx + 1, zeros_index + 1});
            } else {
                auto top1 = minHeap.top();
                auto top2 = singleHeap.top();
                int val2 = top2.first;
                di vec = top1.first; 
                int idx = top1.second;     
                int idx2 = top2.second;   

                minHeap.pop();
                singleHeap.pop();

                if (vec[0] < val2) {
                    moves.PB({idx + 1, zeros_index + 1});
                    vec.pop_front();
                    a[idx] = vec;
                    if (!vec.empty()) minHeap.push({vec, idx});
                } else {
                    moves.PB({idx2 + 1, zeros_index + 1});
                }
  
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