// #include <bits/stdc++.h>

// using namespace std;

// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define REP(i, a, b) for(int i = a; i <= b; ++i)
// #define FWD(i, a, b) for(int i = a; i < b; ++i)
// #define REV(i, a, b) for(int i = a; i >= b; --i)
// #define ALL(a) (a).begin(), (a).end()
// #define SIZE(a) (int)((a).size())

// const int INF = 1e9 + 7;
// const ll LINF = 1e18 + 7;
// const int MOD = 1e9 + 7;

// void fast_io() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// } 

// std::vector<int> vec(10e6+5, 0);
// std::vector<int> vec2;

// void solve() {
//     int n; std::cin >> n;
//     ll a, b, c; std::cin >> a >> b >> c;
//     ll x, y; std::cin >> x >> y;
//     if (c < 10e6) {
//         fill(vec.begin(), vec.end(), 0);
//         ll sb = a;
//         for (int i = 0; i < n; i++) {
//             vec[sb]++;
//             sb = (sb*b+a)%c;
//         }
//         ll V = 0;
//         for (int i = 0; i < 10e6+5; i++) {
//             if (vec[i] == 0) continue;
//             for (int j = 0; j < vec[i]; j++) {
//                 V = (V*x+i)%y;
//             }
//         }
//         std::cout << V << "\n";
//     } else {
//         vec2.clear();
//         ll sb = a;
//         for (int i = 0; i < n; i++) {
//             vec2.PB(sb);
//             sb = (sb*b+a)%c;
//         }
//         std::sort(ALL(vec2));
//         ll V = 0;
//         for (int z: vec2) {
//             V = (V*x+z)%y;
//         }
//         std::cout << V << "\n";
//     }
// }

// int main() {
//     fast_io();
//     int T; std::cin >> T;
//     while (T--) solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, x, y;
long long base, base_log2;
long long arr[1000009];
vector<long long>ve[1<<10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc=0;tc<T;tc++){
        cin >> n >> a >> b >> c >> x >> y;
        
        // Generate sequence
        long long max_val = a;
        arr[0] = a;
        for (long long i=1;i<n;i++){
            arr[i] = ((arr[i-1]*b)%c + a)%c;
            max_val = max(max_val, arr[i]);
        }
        
        base_log2 = 10; 
        long long base = 1<<base_log2;
        long long max_d = (long long)((log(max_val))/(log(base)));
        for (long long digit=0; digit<max_d; digit++){
            for (int i=0;i<n;i++){
                ve[(arr[i]>>(digit*base_log2))&(base-1)].emplace_back(arr[i]);
            }
            long long index = 0;
            for (int j=0; j<base;j++){
                for(auto i: ve[j]){
                    arr[index] = i;
                    index++;
                }
                ve[j].clear();
            }
        }
        
        long long V = 0;
        for (int i=0;i<n;i++){
            V = ((long long)(V*x)+ arr[i])%y ;
        }
        cout << V << endl;
    }
    return 0;
}