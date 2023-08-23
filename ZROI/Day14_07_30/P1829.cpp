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
const long long mod = 20101009;
const long long _2_inv = 10050505;
const long long _4_inv = 15075757;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long pri[10000005],mu[10000005],tot,ans1[10000005],ans;
bool vis[10000005];
void get_mu(long long n){
    mu[1]=1;
    for(long long i = 2;i<=n;i++){
        if(!vis[i]){
            pri[++tot]=i;
            mu[i]=-1;
        }
        for(long long j = 1;i*pri[j]<=n&&j<=tot;j++){
            long long m=i*pri[j];
            vis[m]=1;
            if(i%pri[j]==0){
                mu[m]=0;
                break;
            }
            mu[m]=-mu[i];
        }
    }
}
long long g(long long n,long long m){
    return (n*(n+1)%mod*m%mod*(m+1)%mod*_4_inv)%mod;
}
long long sum(long long n,long long m){
    long long res=0;
    for(long long l = 1,r;l<=min(m,n);l=r+1){
        r=min(n/(n/l),m/(m/l));
        res=res+(ans1[r]-ans1[l-1]+mod)%mod*g(n/l,m/l);
    }
    return (res%mod+mod)%mod;
}
int main(){
    long long n=read(),m=read();
    if(n>m) swap(n,m);
    get_mu(10000005);
    for(long long i = 1;i<=n;i++){
        ans1[i]=(ans1[i-1]+(mu[i]+mod)*i%mod*i%mod)%mod;
    }
    for(long long l = 1,r;l<=n;l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+(r-l+1)*(l+r)%mod*_2_inv%mod*sum(n/l,m/l)%mod)%mod;
    }
    cout<<(ans%mod+mod)%mod;
    return 0;
}