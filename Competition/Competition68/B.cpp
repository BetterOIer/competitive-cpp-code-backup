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
const int mod = 1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int dp[2005][2005],n,m,ans=0;
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++) dp[1][i]=1;
    for(int i = 1;i<m;i++){
        for(int j = 1;j<=n;j++){
            (ans+=dp[i][j])%=mod;
            for(int k = j;k<=n;k+=j)(dp[i+1][k]+=dp[i][j])%=mod;
        }
    }
    for(int i = 1;i<=n;i++) (ans+=dp[m][i])%=mod;
    cout<<ans<<endl;
    return 0;
}