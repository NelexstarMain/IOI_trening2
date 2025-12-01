#include <bits/stdc++.h>
using namespace std;

struct Transition {
    long long cost;
    string sequence;

    Transition() : cost(numeric_limits<long long>::max()) {}
};

long long INF = numeric_limits<long long>::max() / 2;

int get_lcp(const string& s1, const string& s2) {
    int len = 0;
    while (len < s1.length() && len < s2.length() && s1[len] == s2[len])
        len++;
    return len;
}

Transition calculate_transition(const string& prev, const string& curr) {
    Transition t;

    if (prev.empty()) {
        t.cost = (long long)curr.length() + 1;
        t.sequence = curr + "E";
        return t;
    }

    int lcp = get_lcp(prev, curr);
    long long cost_A = (long long)curr.length() + 1;
    long long cost_B = 2 + (prev.length() - lcp) + (curr.length() - lcp);

    if (cost_A <= cost_B) {
        t.cost = cost_A;
        t.sequence = curr + "E";
    } else {
        t.cost = cost_B;
        t.sequence = "T";
        for (int i = 0; i < prev.length() - lcp; ++i)
            t.sequence += 'B';
        t.sequence += curr.substr(lcp);
        t.sequence += 'E';
    }

    return t;
}

void solve_bitmask_dp() {
    int n;
    if (!(cin >> n)) return;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int max_mask = 1 << n;
    vector<vector<long long>> DP(max_mask, vector<long long>(n, INF));
    vector<vector<int>> Parent(max_mask, vector<int>(n, -1));

    string empty_str = "";
    for (int i = 0; i < n; ++i)
        DP[1 << i][i] = (long long)s[i].length() + 1;

    for (int mask = 1; mask < max_mask; ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) && DP[mask][i] < INF) {
                for (int j = 0; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        int next_mask = mask | (1 << j);
                        Transition t = calculate_transition(s[i], s[j]);
                        long long new_cost = DP[mask][i] + t.cost;
                        if (new_cost < DP[next_mask][j]) {
                            DP[next_mask][j] = new_cost;
                            Parent[next_mask][j] = i;
                        }
                    }
                }
            }
        }
    }

    int final_mask = max_mask - 1;
    long long min_cost = INF;
    int last_page_index = -1;

    for (int i = 0; i < n; ++i) {
        if (DP[final_mask][i] < min_cost) {
            min_cost = DP[final_mask][i];
            last_page_index = i;
        }
    }

    if (last_page_index == -1) {
        cout << "0\n\n";
        return;
    }

    vector<int> path;
    int current_mask = final_mask;
    int current_page = last_page_index;
    while (current_page != -1) {
        path.push_back(current_page);
        int prev_page = Parent[current_mask][current_page];
        current_mask ^= (1 << current_page);
        current_page = prev_page;
    }
    reverse(path.begin(), path.end());

    string result_sequence = "";
    result_sequence += calculate_transition(empty_str, s[path[0]]).sequence;
    for (size_t i = 1; i < path.size(); ++i) {
        result_sequence += calculate_transition(s[path[i-1]], s[path[i]]).sequence;
    }

    cout << result_sequence.length() << "\n";
    cout << result_sequence << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve_bitmask_dp();
}
