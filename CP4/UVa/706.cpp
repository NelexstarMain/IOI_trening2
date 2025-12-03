#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<bool>> numbers = {
    {true,  true,  true,  true,  true,  true,  false},
    {false, true,  true,  false, false, false, false},
    {true,  true,  false, true,  true,  false, true },
    {true,  true,  true,  true,  false, false, true },
    {false, true,  true,  false, false, true,  true },
    {true,  false, true,  true,  false, true,  true },
    {true,  false, true,  true,  true,  true,  true },
    {true,  true,  true,  false, false, false, false},
    {true,  true,  true,  true,  true,  true,  true },
    {true,  true,  true,  true,  false, true,  true }
};

void print_horizontal(const string& num, int s, int seg_idx) {
    for (int i = 0; i < num.size(); ++i) {
        int d = num[i] - '0';
        
        cout << " "; 
        
        for (int k = 0; k < s; ++k) {
            cout << (numbers[d][seg_idx] ? "-" : " ");
        }
        
        cout << " "; 
        
        if (i < num.size() - 1) {
            cout << " "; 
        }
    }
    cout << "\n";
}

void print_vertical(const string& num, int s, int seg_left, int seg_right) {
    for (int row = 0; row < s; ++row) {
        for (int i = 0; i < num.size(); ++i) {
            int d = num[i] - '0';
            cout << (numbers[d][seg_left] ? "|" : " "); 
            for (int k = 0; k < s; ++k) cout << " ";     
            cout << (numbers[d][seg_right] ? "|" : " ");
            
            if (i < num.size() - 1) cout << " "; 
        }
        cout << "\n";
    }
}

void solve() {
    int s;
    string num;

    while (cin >> s >> num && (s != 0 || num != "0")) {
        print_horizontal(num, s, 0);

        print_vertical(num, s, 5, 1);

        print_horizontal(num, s, 6);

        print_vertical(num, s, 4, 2);

        print_horizontal(num, s, 3);

        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}