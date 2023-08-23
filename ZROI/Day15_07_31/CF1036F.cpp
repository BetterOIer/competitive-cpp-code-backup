/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline long long read(){register long long x=0,f=1;register char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
bool vis[101];
int pri[101],mu[101],tot;
inline void get_mu(register int x=100){
    mu[1]=1;
    for(register int i = 2;i<=x;i++){
        if(!vis[i]){
            pri[++tot]=i;
            mu[i]=-1;
        }
        for(register int j = 1;j<=tot&&i*pri[j]<=x;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
            mu[i*pri[j]]=-mu[i];
        }
    }
}
long double qpow(long double a,long long b){
    if(b==1)return a;
    if(b%2==1)return qpow(a,b-1)*a;
    register long double temp=pow(a,b/2);
    return temp*temp;
}
int main(){
    get_mu();
    register long long t=read();
    while(t--){
        n=read();
        register long long ans=0;
        for(register int i=1;i<=60;i++){
            register long long temp=(long long)(pow(n,1.l/i))+1;
            while(qpow(temp,i)>n)temp--;
            ans+=mu[i]*(temp-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}