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
const long long mod=1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
bool prime[1000005];
long long ans=1;
int main(){
    long long n=read();
    for(long long i = 2,cnt=n,sum=0;i<=n;i++,cnt=n,sum=0){
        if(prime[i])continue;
        for(long long j=(i<<1);j<=n;j+=i) prime[j]=true;
        while(cnt) sum=(sum+cnt/i)%mod,cnt/=i;
        ans=(ans*(((sum<<1)+1)%mod))%mod;
    }
    cout<<ans;
    return 0;
}