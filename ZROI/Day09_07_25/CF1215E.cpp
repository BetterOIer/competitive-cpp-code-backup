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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
long long a[400005];
long long tim[22];
long long val[22][22];
long long dp[(1<<20)+3];
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        a[i]=read();tim[a[i]]++;
        for(long long j = 1;j<=20;j++){
            val[j][a[i]]+=tim[j];
        }
    }
    for(long long i = 1,j;i<(1<<20);i++){
        dp[i]=1e18;
        for(long long fi = 0;fi<20;fi++){
            if(1<<fi &i){
                j = 1<<fi^i;
                long long sum=0;
                for(long long se = 0;se<20;se++){
                    if(1<<se&j)sum+=val[fi+1][se+1];
                }
                dp[i]=min(dp[i],dp[j]+sum);
            }
        }
    }
    cout<<dp[(1<<20)-1];
    return 0;
}