#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=10000005;
bool vis[N];
int n,num,pr[N],phi[N];
long long sum[N];
int main(){
	scanf("%d",&n);
	memset(vis,1,sizeof(vis));
	vis[1]=0;phi[1]=1;
	for (int i=2;i<=n;++i){
		if (vis[i]) phi[i]=i-1,pr[++num]=i;
		for (int j=1;j<=num&&pr[j]*i<=n;++j){
			vis[pr[j]*i]=0;
			if (__gcd(pr[j],i)==1) phi[pr[j]*i]=phi[pr[j]]*phi[i];
				else phi[pr[j]*i]=pr[j]*phi[i];
			if (i%pr[j]==0) break;
		}
	}
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+phi[i];
	long long ans=0;
	for (int i=1;i<=num&&pr[i]<=n;++i) 
		ans+=(sum[n/pr[i]]<<1)-1;
	printf("%lld\n",ans);
	return 0;
}
