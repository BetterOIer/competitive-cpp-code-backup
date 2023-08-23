#include<iostream>
using namespace std;
int a[100001],dp[50000];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n/2;i++) for(int j=2;i*j<=n;j++) a[i*j]+=i;
    for(int i = 1;i<=n;i++) for(int w= n;w>=i;w--) dp[w]=max(dp[w],dp[w-i]+a[i]);
    cout<<dp[n];
    return 0;
}