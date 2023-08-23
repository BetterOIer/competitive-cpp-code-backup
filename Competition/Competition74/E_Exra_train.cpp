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
long long n,m,ans1=1,ans2=1,ans;
int main(){
    freopen("train.in","r",stdin);
    freopen("train.out","w",stdout);
    n=read(),m=read();
    for(long long i = 1;i<=m;i++) ans1=(ans1*2LL)%mod;
    for(long long i = 1;i<m;i++) ans2=(ans2*(n+1LL))%mod;
    ans=1LL*(n+1LL-m)*ans1%mod*ans2%mod;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}