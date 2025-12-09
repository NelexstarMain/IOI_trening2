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
#define ALL(a) (a).begin(), (a).end()

const int TOTAL_DAYS = 365;
const int CURRENT_DAY = 300; 


std::vector<int> mon = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int string_day(const std::string& z) {
    int s = 0;
    int m = (z[0]-'0')*10+(z[1]-'0');
    int d = (z[3]-'0')*10+(z[4]-'0');
    for (int i = 0; i < m - 1; ++i) {
        s += mon[i];
    }
    s += d;
    return s;
}

std::string day_string(int d) {
    if (d > TOTAL_DAYS) d -= TOTAL_DAYS;
    if (d <= 0) d += TOTAL_DAYS;

    int current_day = d;
    int month_index = 0; 
    while (current_day > mon[month_index]) {
        current_day -= mon[month_index];
        month_index++;
    }
    int month = month_index + 1;
    int day_in_month = current_day;
    char buffer[6];
    std::sprintf(buffer, "%02d-%02d", month, day_in_month);
    return std::string(buffer);
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n; 
    std::cin >> n;
    std::set<int> unique_birthdays;
    for (int i = 0; i < n; i++) {
        std::string s, k; 
        std::cin >> s >> k;
        unique_birthdays.insert(string_day(k)); 
    }
    
    std::vector<int> sorted_birthdays(unique_birthdays.begin(), unique_birthdays.end());
    
    if (sorted_birthdays.empty()) {
        std::cout << "10-28" << std::endl;
        return;
    }
    std::map<int, int> best; 
    int max_gap = 0;
    int num_unique = sorted_birthdays.size();
    for (int i = 0; i < num_unique; ++i) {
        int prev_day = sorted_birthdays[i];
        int next_day = sorted_birthdays[(i + 1) % num_unique];
        int gap;
        if (next_day > prev_day) {
            gap = next_day - prev_day;
        } else {
            gap = TOTAL_DAYS - prev_day + next_day;
        }
        if (gap >= max_gap) {
            
            if (gap > max_gap) {
                max_gap = gap;
                best.clear(); 
            }

            int bobby_day = next_day - 1;
            if (bobby_day <= 0) {
                bobby_day = TOTAL_DAYS; 
            }
            int shifted_day = bobby_day;
            if (bobby_day <= CURRENT_DAY) {
                shifted_day += TOTAL_DAYS;
            }
            best[shifted_day] = bobby_day;
        }
    }
    auto it = best.begin();
    int result_day = it->second;
    
    std::cout << day_string(result_day) << std::endl;
}

int main() {
    fast_io();
    solve();
    return 0;
}