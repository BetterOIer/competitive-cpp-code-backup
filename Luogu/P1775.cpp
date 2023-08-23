#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dp[305][305],sum[305];
int main(){
    memset(dp,0x3f,sizeof dp);
    int n=read();
    for(int i = 1;i<=n;i++){
        sum[i]=read();
        dp[i][i]=0;
        sum[i]+=sum[i-1];
    }
    for(int len=2;len<=n;++len){
        for(int l = 1;l<=n-len+1;l++){
            int r=l+len-1;
            for(int k =l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
            dp[l][r]+=(sum[r]-sum[l-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}