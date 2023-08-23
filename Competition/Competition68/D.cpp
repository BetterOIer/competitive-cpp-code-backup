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
const long long mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k,l,r,ans=0;
long long a[1005],h[1024],idx=0;
long long dp[1005][1024],f[1005][1024];
bool count(long long x){
    long long tot = __builtin_popcount(x);
    return l<=tot&&tot<=r;
}
long long get(long long st,long long x){
    long long tot = 0;
    for(long long i = 0;x;i++){
        tot+=a[st+i]*(x%2);
        tot%=mod;
        x/=2;
    }
    return tot;
}
int main(){
    n=read(),k=read(),l=read(),r=read();
    for(long long i = 1;i<=n;i++) a[i]=read();
    if(n<k) k=n,l=1,r=n;
    for(long long i=0;i<(1<<k);i++){
        if(count(i)){
            h[++idx] = i;
        }
    }
    for(long long i = 1;i<=idx;i++){
        dp[1][h[i]] = get(1,h[i]);
        f[1][h[i]] = 1;
    }
    for(long long i = 2;i<=n+1-k;i++){
        for(long long j = 1;j<=idx;j++){
            long long gx=(h[j]>>1)|(1<<(k-1));
            if(count(gx)){
            dp[i][gx]+=dp[i-1][h[j]];
            dp[i][gx]%=mod;
            f[i][gx]+=f[i-1][h[j]];
            f[i][gx]%=mod;
            dp[i][gx]+=a[i+k-1]*f[i-1][h[j]];
            dp[i][gx]%=mod;
            }
            gx=h[j]>>1;
            if(count(gx)){
            dp[i][gx]+=dp[i-1][h[j]];
            dp[i][gx]%=mod;
            f[i][gx]+=f[i-1][h[j]];
            f[i][gx]%=mod;
            }
        }
    }
    for(long long i = 1;i<=idx;i++){
        (ans+=dp[n-k+1][h[i]])%=mod;
    }
    cout<<ans<<endl;
    return 0;
}