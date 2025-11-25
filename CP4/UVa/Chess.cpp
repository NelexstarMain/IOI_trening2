#include <bits/stdc++.h>

using namespace std;

using pii = std::pair<int,int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

std::vector<pii> moves(pii point) {
    std::vector<pii> res;
    int x = point.first;
    int y = point.second;

    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (1 <= nx && nx <= 8 && 1 <= ny && ny <= 8) {
            res.emplace_back(nx, ny);
            nx += dx[d];
            ny += dy[d];
        }
    }
    return res;
}

void solve() {
    char fchar, schar;
    int fint, sint; 

    std::cin >> fchar;
    std::cin >> fint;
    std::cin >> schar;
    std::cin >> sint;
    

    int fx = fchar - 'A' + 1;  
    int sx = schar - 'A' + 1;


    if (((fx+fint)%2)!=((sx+sint)%2)) {
        std::cout << "Impossible" << "\n";
        return;
    }
    std::vector<pii> movess;
    if (fx == sx && fint == sint) {
        std::cout << "0 ";
        movess.push_back({fx, fint});
    } else if (std::abs(fx - sx) == std::abs(fint - sint)) {
        std::cout << "1 ";
        movess.push_back({fx, fint});
        movess.push_back({sx, sint});
    } else {
        std::cout << "2 ";
        std::vector<pii> first = moves({fx, fint});
        std::vector<pii> second = moves({sx, sint});
        std::sort(first.begin(), first.end());
        std::sort(second.begin(), second.end());
        movess.push_back({fx, fint});
        vector<pii> intersection;
        set_intersection(first.begin(), first.end(), second.begin(), second.end(),
                        back_inserter(intersection));

        movess.push_back(intersection[0]);
        movess.push_back({sx, sint});
    }
    for (auto x: movess) {
        char A = 'A' + (x.first-1);
        std::cout << A << " " << x.second << " ";
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    int t; std::cin >> t;
    while (t--) solve();
    return 0;
}
