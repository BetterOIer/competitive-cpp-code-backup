#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,m,k;
    n=read(),m=read(),k=read();
    int dp[k+1][n-k];
    memset(dp,0,sizeof dp);
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            dp[j][i-j-1]=min(dp[j-1][i-j-1],dp[j][i-j-2]),
        }
    }
    //fclose(stdin);
    //fclose(stdout);
}