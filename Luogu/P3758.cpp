#include<iostream>
#include<cstring>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,m;
const long long mod =2017;
struct Matrix{
    long long a[103][103];
    inline Matrix operator * (const Matrix &w)const{
        Matrix ret;
        memset(ret.a,0,sizeof ret.a);
        for(long long i = 0;i<=n;i++){
            for(long long j = 0;j<=n;j++){
                for(long long k = 0;k<=n;k++){
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*w.a[k][j]%mod)%mod;
                }
            }
        }
        return ret;
    }
}digi;
Matrix qpow(Matrix &digi,long long k){
    Matrix res;
    memset(res.a,0,sizeof res.a);
    for(long long i = 0;i<=n;i++){
        res.a[i][i]=1;
    }
    while(k){
        if(k&1)res=res*digi;
        digi = digi*digi;
        k>>=1;
    }
    return res;
}
int main(){
    n=read(),m=read();
    for(long long i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        digi.a[u][v]=digi.a[v][u]=1;
    }
    for(long long i=0;i<=n;i++) digi.a[i][i]=1;
    for(long long i=1;i<=n;i++) digi.a[i][0]=1;
    long long ans=0;
    long long k=read();
    Matrix Ans=qpow(digi,k);
    for(long long i=0;i<=n;i++) ans=(ans+Ans.a[1][i])%mod;
    printf("%lld\n",ans);
}