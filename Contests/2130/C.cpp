
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
const int N=1000010;
int T,n;
int a[N],b[N];

void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
}

void solve()
{
    vector<int> tag(n+4,1),ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(a[j]<=a[i]&&b[i]<=b[j]) tag[i]=0;
        }
        if(tag[i]) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
}

int main()
{
    fastio;

    cin>>T;
	while(T--)
	{
		init();
		solve();
	}

	return 0;
}
