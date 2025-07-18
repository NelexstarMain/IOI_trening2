// #include <iostream>
// #include <vector>
// using namespace std;

// int binary(int num, const vector<int>& a) {
//     int left = 0, right = a.size() - 1;
//     int res = -1;

//     while (left <= right) {
//         int mid = (left + right) / 2;
//         if (a[mid] <= num) {
//             res = mid;
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }

//     return res;  
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n), b(m);

//     for (int& x: a) cin >> x;
//     for (int& x: b) cin >> x;

//     for (int x: b) {
//         int idx = binary(x, a);
//         if (x != -1) {
//             cout << a[idx] << endl;
//             a.erase(a.begin() + idx);
//         }
//     }

// }

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price; cin >> price;  
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int max_price; cin >> max_price;

        auto it = tickets.upper_bound(max_price);

        if (it == tickets.begin()) {

            cout << -1 << "\n";
        } else {
            --it; 
            cout << *it << "\n";
            tickets.erase(it);  
        }
    }

    return 0;
}
