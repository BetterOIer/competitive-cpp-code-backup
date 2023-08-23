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
long long n,p,ans=0,s=1,k,inv,kx;
long long a[5000005],pre[5000005],sub[5000005];
/* void exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0) return x=1,y=0,void();
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
long long get(long long num){
    long long x,y;
    exgcd(num,p,x,y);
    return (x%p+p)%p;
} *///!TLE//

inline long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)(res*=1LL*a)%=p;
        (a*=1LL*a)%=p,b>>=1;
    }
    return res;
}

int main(){
    n=read(),p=read(),kx=k=read();
    for(int i = 1;i<=n;i++) a[i]=read(),s=1LL*s*a[i]%p;
    pre[0]=sub[n+1]=1,inv=qpow(s,p-2);
    for(int i = 1;i<=n;i++) pre[i]=(1LL*pre[i-1]*a[i])%p;
    for(int i = n;i>=1;i--) sub[i]=(1LL*sub[i+1]*a[i])%p;
    for(int i = 1;i<=n;i++) (ans+=(1LL*kx*inv%p*pre[i-1]%p*sub[i+1]%p))%=p,kx=kx*k%p;
    printf("%d",ans);
    return 0;
}