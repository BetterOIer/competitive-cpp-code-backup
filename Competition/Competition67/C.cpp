#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int t;
int jc[100005],n,m;
const int mod=998244353;
int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res*=x,res%=mod ;
        x*=x;
        x%=mod;
        y>>=1;
    }
    return res;
}

signed main(){
    t=read();
    jc[0]=1;
    for(int i=1;i<=100000;i++)jc[i]=jc[i-1]*i,jc[i]%=mod ;
    while(t--){
        n=read(),m=read();
        int ans=jc[n]*jc[n-1]%mod*qpow(jc[m-1],mod-2)%mod*qpow(jc[n-m],mod-2)%mod;
        cout<<ans<<endl;
    }
}