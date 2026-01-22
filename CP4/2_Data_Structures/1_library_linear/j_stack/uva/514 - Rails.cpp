#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n) {
        if (n == 0) break;

        while (true) {
            vector<int> target(n);
            int first_num;
            cin >> first_num;

            if (first_num == 0) break;

            target[0] = first_num;
            for (int i = 1; i < n; ++i) {
                cin >> target[i];
            }
            stack<int> st;
            int next = 1;
            int pos = 0;

            while (pos < n) {
                if (!st.empty() && st.top() == target[pos]) {
                    st.pop();
                    pos++;
                }
                else if (next <= n) {
                    st.push(next++);
                }
                else {
                    break;
                }
            }

            bool possible = (pos == n) && st.empty();
            cout << (possible ? "Yes" : "No") << '\n';
        }
        std::cout << "\n";
    }

    return 0;
}
