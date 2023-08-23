/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
long long pri[10005],maxn=1;
bool ok[10000005];
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        pri[i]=read();maxn*=pri[i];
    }
    for(long long i = 1;i<=n;i++){
        long long maxt = maxn/pri[i];
        for(long long j = 1;j<=maxt;j++){
            ok[j*pri[i]]=1;
        }
    }
    long long ans=0;
    for(long long i = 1,last = 0;i<=maxn;i++){
        if(ok[i]){
            (ans+=(i-last)%mod*(i-last)%mod)%=mod;
            last = i;
        }
    }
    cout<<ans;
    return 0;
}