#include <bits/stdc++.h>
using namespace std;

void rebalance(deque<int>& A, deque<int>& B) {
    if (A.size() > B.size() + 1) {
        B.push_front(A.back());
        A.pop_back();
    } else if (B.size() > A.size()) {
        A.push_back(B.front());
        B.pop_front();
    }
}

void solve() {
    int n; 
    if (!(cin >> n)) return;
    
    deque<int> A, B; 

    for (int i = 0; i < n; i++) {
        string curr; cin >> curr;
        
        if (curr == "push_back") {
            int val; cin >> val;
            B.push_back(val);
            rebalance(A, B);
        } 
        else if (curr == "push_front") {
            int val; cin >> val;
            A.push_front(val);
            rebalance(A, B);
        } 
        else if (curr == "push_middle") {
            int val; cin >> val;
            A.push_back(val);
            rebalance(A, B);
        } 
        else if (curr == "get") {
            int index; cin >> index;
            if (index < (int)A.size()) {
                cout << A[index] << "\n";
            } else {
                cout << B[index - A.size()] << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}