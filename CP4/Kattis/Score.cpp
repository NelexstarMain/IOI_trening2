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
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

pii addtime(pii start, pii end) {
    int minutes = start.first + end.first + ((start.second+end.second)/60);
    int seconds = (start.second+end.second)%60;
    return {minutes, seconds};
}

pii minustime(pii start, pii end) {
    int final_minutes = end.first - start.first;
    int final_seconds = end.second - start.second;

    if (final_seconds < 0) {
        final_minutes--;
        final_seconds += 60;
    }
    return {final_minutes, final_seconds};
}

void solve() {
    int n; std::cin >> n;
    pii htime = {0, 0};
    pii atime = {0, 0};
    pii btime = {0, 0};
    int hscore = 0, ascore = 0;
    for (int i = 0; i < n; i++) {
        char team; std::cin >> team;
        int points; std::cin >> points;
        pii ptime = {};
        std::string time; std::cin >> time;
        if (time.size() == 5) {
            int minuts = (time[0]-'0')*10+(time[1]-'0');
            int secunds = (time[3]-'0')*10+(time[4]-'0');
            ptime = {minuts, secunds};
        } else if (time.size() == 4) {
            int minuts = (time[0]-'0');
            int secunds = (time[2]-'0')*10+(time[3]-'0');
            ptime = {minuts, secunds};
        }
        if (hscore > ascore) {
            htime = addtime(htime, minustime(btime, ptime));
        } else if (hscore < ascore) {
            atime = addtime(atime, minustime(btime, ptime));
        } 
        if (team == 'H') hscore += points;
        if (team == 'A') ascore += points;
        btime = ptime;
        
    }
    if (hscore > ascore) {
        std::cout << "H ";
        htime = addtime(htime, minustime(btime, {32, 00}));
    } else {
        std::cout << "A ";
        atime = addtime(atime, minustime(btime, {32, 00}));
    }
    std::cout << htime.first << ":" << ((htime.second > 9) ? "" : "0") << htime.second << " " << atime.first << ":" << ((atime.second > 9) ? "" : "0") << atime.second << "\n";
} 

int main() {
    fast_io();
    solve();
    return 0;
}
