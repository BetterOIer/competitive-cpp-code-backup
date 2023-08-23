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
int dp[60][262145],n,ans;
int main(){
    n=read();
    for(int i = 1,x;i<=n;i++){
        x=read();
        dp[x][i]=i+1;
    }
    for(int i = 2;i<=58;i++){
        for(int j = 1;j<=n;j++){
            if(!dp[i][j])dp[i][j]=dp[i-1][dp[i-1][j]];
            if(dp[i][j])ans=i;
        }
    }
    cout<<ans;
    return 0;
}