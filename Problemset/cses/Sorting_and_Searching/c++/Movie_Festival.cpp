#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> films(n);
    for (auto& x : films) cin >> x.first >> x.second;

    sort(films.begin(), films.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int count = 0;
    int end_time = 0;

    for (auto& film : films) {
        if (film.first >= end_time) {
            ++count;
            end_time = film.second;
        }
    }

    cout << count << '\n';
    return 0;
}
