#include<iostream>
#include<cstring>
using namespace std;
const int maxn=60;
int a[maxn][maxn],n,m;
int dp[2*maxn][maxn][maxn];
int main(){
    cin>>m>>n;
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[2][1][1]=0;
    for(int w = 3;w<=m+n-1;w++){
        for(int i = 1;i<=n-1;i++){
            for(int j = i+1;j<=n;j++){
                int ans=dp[w][i][j];
                if(ans<dp[w-1][i][j]) ans=dp[w-1][i][j];
                if(ans<dp[w-1][i-1][j]) ans=dp[w-1][i-1][j];
                if(ans<dp[w-1][i][j-1]) ans=dp[w-1][i][j-1];
                if(ans<dp[w-1][i-1][j-1]) ans=dp[w-1][i-1][j-1];
                if(ans==-1)continue;
                dp[w][i][j]=ans+a[w-i][i]+a[w-j][j];
            }
        }
    }
    cout<<dp[m+n-1][n-1][n];
}