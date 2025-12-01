#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		if(max(n, m) - min(n, m) > k || k > max(n, m)){
			cout << "-1" << endl;
			continue;
		}
		else{
			pair<int, int> use1 = {n, 0}, use2 = {m, 1};
			if(m > n) swap(use1, use2);
			for(int i = 0; i < k; i++){
				cout << use1.second;
				use1.first--;
			}
			while(use2.first > 0){
				cout << use2.second;
				use2.first--;
				swap(use1, use2);
			}
			while(use1.first > 0){
				cout << use1.second;
				use1.first--;
			}
			cout << "\n";
		}
	}
}