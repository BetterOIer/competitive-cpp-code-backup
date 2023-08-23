#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f, maxn=100007, mod=1e9+7;
const ll P=19260817;
const int p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int n;
ll dp[2][1<<19];
ll cnt[75];
int I=0;
ll h[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int rt;
		scanf("%d",&rt);
		cnt[rt]++;
	}
	h[0]=1;
	dp[0][0]=1; 
	for(int i=1;i<=n;i++)h[i]=(h[i-1]<<1)%mod;
	for(int i=1;i<=70;i++){
		if(cnt[i]==0)continue;
		I^=1;
		memset(dp[I],0,sizeof(dp[I]));
		for(int mask=0 ; mask< (1<<19) ; mask++){
			int mask1=mask;
			int x=i;
			for(int j=0;j<19&&x>=p[j];j++){
				while(x%p[j]==0)x/=p[j],mask1^=(1<<j);
			}
            cout<<mask<<" "<<mask1<<endl;
			(dp[I][mask1]+=1LL*dp[I^1][mask]*h[cnt[i]-1]%mod)%=mod;
			(dp[I][mask]+=1LL*dp[I^1][mask]*h[cnt[i]-1]%mod)%=mod;
            if(dp[I][mask1]||dp[I][mask])cout<<i<<' '<<mask<<' '<<mask1<<' '<<dp[I][mask1]<<" "<<dp[I][mask]<<endl;
        }
	}
	printf("%I64d\n",(dp[I][0]-1+mod)%mod);
    return 0;
}