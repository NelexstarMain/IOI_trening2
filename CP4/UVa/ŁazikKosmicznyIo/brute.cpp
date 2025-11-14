#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    string seq;
    cin >> seq;

    ll dx = 0, dy = 0;
    for(char c : seq){
        if(c == 'G') dx--;
        else if(c == 'D') dx++;
        else if(c == 'L') dy--;
        else if(c == 'P') dy++;
    }

    dx = ((dx % n) + n) % n;
    dy = ((dy % m) + m) % m;

    // warunek generowania całej kratki torusa
    if (std::gcd(dx, n) == 1 && std::gcd(dy, m) == 1) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }
}
