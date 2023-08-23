#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,now,k,pos[100005],cd[100005];
long long a[100005],ans;
int main(){
	n=read();
	for(long long i=1;i<=n;++i) a[i]=read();
	now=0; ans=0;
	for(long long i=1;i<=n;++i) {
		++now;
		pos[now]=i;
		cd[now]=a[i];
		for(long long j=now-1;j>=1;--j) cd[j]=__gcd(cd[j],cd[j+1]);
		k=0;
		for(long long j=1;j<=now;) {
			++k;
			pos[k]=pos[j];
			cd[k]=cd[j];
			while(cd[k]==cd[j]) ++j;
		}
		now=k;
		for(long long j=1;j<=now;++j) ans=max(ans,(i-pos[j]+1)*cd[j]);
	}
	printf("%lld",ans);
	return 0;
}
