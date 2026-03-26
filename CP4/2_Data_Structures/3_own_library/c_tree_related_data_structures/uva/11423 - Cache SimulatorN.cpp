#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define PB push_back
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class NTree {
    private:
        int S;
        int head, tail, M, listS;
        vector<int> prev, after, val_arr; 
        unordered_map<int, int> ValToIndex;

    public: 
        NTree(int size): S(size), head(-1), tail(-1), M(0), listS(0) {
            prev.assign(size, -1);
            after.assign(size, -1);
            val_arr.assign(size, -1);
        }

        int getM() { return M; }
        void clearM() { M = 0; }

        void NewE(int val) {
            if (S == 0) { 
                M++; 
                return; 
            }

            if (ValToIndex.find(val) == ValToIndex.end()) {
                M++;
                int index;
                if (listS < S) { 
                    index = listS;
                    listS++;
                } else { 
                    index = tail;
                    ValToIndex.erase(val_arr[index]); 
                    tail = prev[tail];
                    if (tail != -1) after[tail] = -1;
                }
                val_arr[index] = val;
                ValToIndex[val] = index;
                after[index] = head;
                prev[index] = -1;
                if (head != -1) prev[head] = index;
                
                head = index;
                if (tail == -1) tail = index; 

            } else {
                int index = ValToIndex[val];                
                if (index == head) return;
                if (prev[index] != -1) after[prev[index]] = after[index];
                if (after[index] != -1) prev[after[index]] = prev[index];
                else tail = prev[index]; 

                after[index] = head;
                prev[index] = -1;
                if (head != -1) prev[head] = index;
                head = index;
            }
        }
};

void solve() {
    int N; 
    if (!(cin >> N)) return; 

    vector<NTree> caches;
    caches.reserve(N);
    for (int i = 0; i < N; ++i) {
        int cap;
        cin >> cap;
        caches.emplace_back(cap);
    }

    string com;
    while (cin >> com && com != "END") {
        if (com == "RANGE") {
            int b, y, k;
            cin >> b >> y >> k;
            for (int i = 0; i < k; ++i) {
                int val = b + y * i;
                for (auto &cache : caches) {
                    cache.NewE(val);
                }
            }
        } else if (com == "ADDR") {
            int val;
            cin >> val;
            for (auto &cache : caches) {
                cache.NewE(val);
            }
        } else if (com == "STAT") { 
            for (int i = 0; i < N; ++i) {
                cout << caches[i].getM();
                if (i < N - 1) cout << " ";
                caches[i].clearM();
            }
            cout << "\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}