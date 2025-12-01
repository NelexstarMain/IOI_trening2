#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> known_by_skill(m + 1); 
    vector<vector<int>> skills_of_person(n);   

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int a;
            cin >> a;
            known_by_skill[a].push_back(i);
            skills_of_person[i].push_back(a);
        }
    }

    vector<bool> visited(n, false);
    int groups = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            groups++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (int skill : skills_of_person[person]) {
                    for (int other : known_by_skill[skill]) {
                        if (!visited[other]) {
                            visited[other] = true;
                            q.push(other);
                        }
                    }
                }
            }
        }
    }

    bool any_skill_known = false;
    for (int i = 0; i < n; i++) {
        if (!skills_of_person[i].empty()) {
            any_skill_known = true;
            break;
        }
    }

    if (!any_skill_known)
        cout << n << '\n'; 
    else
        cout << groups << '\n';

    return 0;
}
