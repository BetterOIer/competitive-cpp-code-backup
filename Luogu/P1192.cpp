#include<iostream>
using namespace std;
const int mod=100003;
int dp[100001],n,k;
int main(){
    cin>>n>>k;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;++i)
		if(i<=k)dp[i]=dp[i-1]*2%mod;
		else dp[i]=dp[i-1]*2-dp[i-k-1],dp[i]%=mod;
	cout<<dp[n];
}