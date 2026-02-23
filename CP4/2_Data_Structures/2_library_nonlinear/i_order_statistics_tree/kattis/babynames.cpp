#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<std::string, null_type, less<std::string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int type;
    ordered_set male, female;
    std::map<std::string, int> gender_map;

    while (cin >> type && type != 0) {
        if (type == 1) {
            std::string name; int gender;
            std::cin >> name >> gender; gender_map[name] = gender;
            if (gender == 1) male.insert(name);
            else female.insert(name);
        } 
        else if (type == 2) {
            std::string name; std::cin >> name; int gender = gender_map[name];
            if (gender == 1) male.erase(name);
            else female.erase(name); gender_map.erase(name);
        } 
        else if (type == 3) {
            std::string start, end; int gender;
            std::cin >> start >> end >> gender; int total = 0;
            auto count_in_range = [&](ordered_set& s) { return s.order_of_key(end) - s.order_of_key(start); };
            if (gender == 0 || gender == 1) total += count_in_range(male);
            if (gender == 0 || gender == 2) total += count_in_range(female);
            std::cout << total << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}