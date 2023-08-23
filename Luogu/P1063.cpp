#include<iostream>
using namespace std;
int each[200];
int dp[305][305],sum[305][305];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    int n=read(),ans=0;
    for(int i = 1;i<=n;i++) each[i]=each[i+n]=read();
    for(int len=3;len<=n+1;len++){
        for(int l = 1,r;l<=n+n+len-1;l++){
            r=l+len-1;
            for(int k = l+1;k<r;k++) dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+each[l]*each[k]*each[r]);
        }
    }
    for(int i = 1;i<=n;i++)ans=max(ans,dp[i][i+n]);
    cout<<ans;
}