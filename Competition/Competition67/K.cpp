#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=998244353;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,x[500005],b[500005];
inline int lb(int x){return (x&-x);}
inline void add(int x){
    while(x<=n+1){
        b[x]+=1;
        x+=lb(x);
    }
}
inline int query(int x){
    int res=0;
    while(x){
        res+=b[x];
        x-=lb(x);
    }
    return res;
}
int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res*=x,res%=mod;
        x*=x;
        x%=mod;
        y>>=1;
    }
    return res;
}
int c[500005];
signed main(){
    n=read(),m=read();
    c[0]=1;
    bool flag=0;
    for(int i=1;i<=m;i++){
        x[i]=read();
        if(x[i]==1)flag=1;
    }
    for(int i=1;i<=2*n;i++)c[i]=c[i-1]*i%mod;
    if(!flag)return puts("0"),0;
    int w=n-m,ans=1;
    for(int i=1;i<=m;i++){
        
    }
    if(n==m){
        cout<<1<<endl;
        return 0;
    }
    //for(int i=1;i<=min(m+1,n-m);i++){
    //    ans+=c[m+1]*qpow(c[i],mod-2)%mod*qpow(c[m+1-i],mod-2)%mod*c[n-m-1]%mod*qpow(c[i-1],mod-2)%mod*qpow(c[n-m-i],mod-2)%mod;
    //    ans%=mod;
    //}
    ans*=c[n+w]*qpow(c[w],mod-2)%mod*qpow(c[m],mod-2)%mod;
    ans%=mod;
    cout<<c[n-m]*ans%mod;
}