#include<iostream>
using namespace std;
long long read(){
    long long c,a=0;
    cin>>c;
    c=-c;
    while(c++){
        a++;
    }
    while(a--){
        c++;
    }
    return c;
}
long long f[1000001],s[2000011],cal[2000011];
long long ksm(long long a,long long b,long long p){long long ans=1;while(b){if(b&1)ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
long long c(long long n,long long m,long long p){return f[n]*ksm(f[m]*f[n-m]%p,p-2,p)%p;}
long long lucas(long long n,long long m,long long p){ return m?c(n%p,m%p,p)*lucas(n/p,m/p,p)%p:1; }
int main(){
    long long p,n;
    cin>>n>>p,f[0]=1;
    for(long long i=1;i<=n;i++) f[i]=f[i-1]*i%p;
    for(long long i=1;i<=n;i++) s[i]=1;
    for(long long i=n;i>=2;i--) s[i>>1]+=s[i];
    for(long long i=n+1;i<=n*2+1;i++) cal[i]=1;
    for(long long i=n;i>=1;i--) cal[i]=lucas(s[i]-1,s[i*2],p)%p*cal[i*2]%p*cal[i*2+1]%p;
    cout<<cal[1];
}
