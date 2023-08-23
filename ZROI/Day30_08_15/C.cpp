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
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n, ans = 0, dp[100005], f[105], g[105];
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        dp[i]=read();
    }
    f[dp[1]]=1;
    for(long long i = 2;i<=n;i++){
        for(long long j = dp[1];j>=0;j--){
            g[j]=(g[j+1]+f[j])%mod;
        }
        for(long long j = 1;j<=dp[1];j++){
            f[j] = (f[j]*((dp[i]-j+1)%mod+mod)%mod+g[j+1]*2%mod)%mod;
        }
    }
    for(long long i = 1;i<=dp[1];i++){
        (ans+=(f[i]*i%mod*i%mod))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}