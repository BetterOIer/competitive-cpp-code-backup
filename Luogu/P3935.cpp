#include<iostream>
using namespace std;
const long long mod = 998244353;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long l,r;
int main(){
    l=read(),r=read();
    long long sum1=0,sum2=0;
    for(long long zuo=1,you;zuo<=r;zuo=you+1){
		you=r/(r/zuo);
		sum1=(sum1+(r/zuo)%mod*((you-zuo+1)%mod)%mod)%mod;
	}
	for(long long zuo=1,you;zuo<=l-1;zuo=you+1){
		you=(l-1)/((l-1)/zuo);
		sum2=(sum2+((l-1)/zuo)%mod*((you-zuo+1)%mod)%mod)%mod;
	}
    cout<<((sum1-sum2)%mod+mod)%mod;
}