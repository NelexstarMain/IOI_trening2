#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,k,arr[maxn],suf[maxn],minsuf[maxn];
bool check_prefix_and_middle(){
   suf[n]=minsuf[n]=arr[n];
   for(int i=n-1;i>=1;i--){
      suf[i]=suf[i+1]+arr[i];
      minsuf[i]=min(minsuf[i+1],suf[i]);
   }
   int s=0;
   for(int i=1;i+2<=n;i++){
      s+=arr[i];
      if(s<0)
         continue;
      if(suf[i+1]>=minsuf[i+2])
         return true;
   }
   return false;
}
void solve(){
   cin>>n>>k;
   for(int i=1;i<=n;i++)
      cin>>arr[i];
   for(int i=1;i<=n;i++)
      if(arr[i]<=k)
         arr[i]=1;
      else
         arr[i]=-1;

   int a=n+1,b=-1;
   int s=0;
   for(int i=1;i<=n;i++){
      s+=arr[i];
      if(s>=0){
         a=i;
         break;
      }
   }
   s=0;
   for(int i=n;i>=1;i--){
      s+=arr[i];
      if(s>=0){
         b=i;
         break;
      }
   }
   if(a+1<b){
      cout<<"YES\n";
      return;
   }
   if(check_prefix_and_middle()){
      cout<<"YES\n";
      return;
   }
   for(int i=1;i<n-i+1;i++)
      swap(arr[i],arr[n-i+1]);
   if(check_prefix_and_middle()){
      cout<<"YES\n";
      return;
   }
   cout<<"NO\n";
   return;
}
int main(){
   int t;
   cin>>t;
   while(t--)
      solve();
   return 0;
}