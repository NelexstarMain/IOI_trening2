    #include <iostream>
    // #include <vector>
    // #include <algorithm>
    #include <string>
    #include <unordered_set>

    using namespace std;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string name;
        unordered_set<char> set;
        int i = 0;

        cin >> name;

        while (name[i]) {
            set.insert(name[i]);
            i++;
        }


        i = set.size();

        if (i%2 == 1) {
            cout << "IGNORE HIM!\n";

        } else {
            cout << "CHAT WITH HER!\n";
        }
        

        
        return 0;
    }
