#include<iostream>

using namespace std;
const int INF = -2147483647 - 1;
const int maxn = 3832;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int h[maxn],dp[2][maxn][2];
int main(){
    freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);
    int n=read(),b=read();
    for(int i = 1;i<=n;i++) h[i]=read();
    for(int i = 0;i<=1;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j][0]=dp[i][j][1]=INF;
        }
    }
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=min(b,i);j++){
            dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
            if(j)dp[i&1][j][1]=max(dp[(i-1)&1][j-1][0],dp[(i-1)&1][j-1][1]+h[i]);
        }
    }
    int ans=max(dp[n&1][b][0],dp[n&1][b][1]);
    for(int i = 0;i<=1;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j][0]=dp[i][j][1]=INF;
        }
    }
    dp[1][1][1]=h[1];
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<=min(b,i);j++){
            dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
            if(j)dp[i&1][j][1]=max(dp[(i-1)&1][j-1][0],dp[(i-1)&1][j-1][1]+h[i]);
        }
    }
    cout<<max(ans,dp[n&1][b][1]);
    return 0;
}