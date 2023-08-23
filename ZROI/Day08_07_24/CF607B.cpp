/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[505];
int dp[505][505];
int main(){
    for(int i = 0;i<=504;i++)
        for(int j = 0;j<=504;j++)dp[i][j]=2147483647;
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        dp[i][i]=1;
        if(i>1){
            if(a[i]==a[i-1])dp[i-1][i]=1;
            else dp[i-1][i] = 2;
        }
    }
    for(int k = 3;k<=n;k++){
        for(int l = 1,r;l<=n+1-k;l++){
            r=l+k-1;
            if(a[l]==a[r])dp[l][r]=dp[l+1][r-1];
            for(int i = l;i<r;i++){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}