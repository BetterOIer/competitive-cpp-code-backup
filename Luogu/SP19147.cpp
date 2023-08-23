#include<iostream>
using namespace std;
const int mod = 1e9+7;
long long fac[1500100];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long kuaisumin(long long a,long long b) {
	long long ans=1;
	while(b) {
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void play_start(){
    fac[0]=1;
    for(int i = 1;i<=1500100;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
int main(){
    play_start();
    int T=read(),n,k;
    for(;T--;){
        n=read(),k=read();
        if(n<=(k<<1)-1){
            printf("%lld\n",fac[k]*fac[n]%mod*kuaisumin(fac[k],mod-2)%mod*kuaisumin(fac[n-k],mod-2)%mod);
        }
        else{
            printf("%lld\n",fac[k]*fac[n-1]%mod*kuaisumin(fac[k-1],mod-2)%mod*kuaisumin(fac[n-k],mod-2)%mod);
        }
    }
}