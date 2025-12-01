#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> s(n), t(n);
    std::map<long long, int> s_rem_counts, t_rem_counts;

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        long long rem = s[i] % k;
        long long partner_rem = (k - rem) % k;
        if (rem == partner_rem || k == 1) { // Obsługa przypadku k=1 oraz gdy reszta jest "swoim partnerem"
            s_rem_counts[rem]++;
        } else {
            s_rem_counts[std::min(rem, partner_rem)]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        long long rem = t[i] % k;
        long long partner_rem = (k - rem) % k;
        if (rem == partner_rem || k == 1) { // Obsługa przypadku k=1 oraz gdy reszta jest "swoim partnerem"
            t_rem_counts[rem]++;
        } else {
            t_rem_counts[std::min(rem, partner_rem)]++;
        }
    }

    if (s_rem_counts == t_rem_counts) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}