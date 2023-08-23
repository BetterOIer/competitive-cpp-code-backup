#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod = 10000007;
long long N,Ans=1;
long long C,G[50];
long long qPow(long long b,long long e){
    long long A=1;
    for(;e;b=b*b%mod,e>>=1) e&1?A=A*b%mod:0;
    return A;
}
int main(){
	N=read();
	for(int j=49;~j;--j){
		for(int i=49;i;--i)
			G[i]+=G[i-1];
		if(N>>j&1) ++G[C++];
	} ++G[C];
	for(int i=1;i<=49;++i)
		Ans=1LL*Ans*qPow(i,G[i])%mod;
	cout<<Ans;
	return 0;
}