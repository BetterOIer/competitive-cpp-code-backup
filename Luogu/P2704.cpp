#include<iostream>
using namespace std;
int n,m,ans,dp[1024][1024][3],a[105],sum[1024];
char x;
int main(){
	cin>>n>>m;
    int base=1<<m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>x,a[i]<<=1,a[i]+=(x=='H'?1:0);
	for(int i=0;i<base;i++){
        int tot=0,per=i;
        while(per){if(per&1) tot++; per>>=1;}
        sum[i]=tot;
    }
	for(int per=0;per<base;per++)if(!(per&a[0] || (per&(per<<1)) || (per&(per<<2))))dp[0][per][0]=sum[per];
	for(int now=0;now<base;now++)for(int per=0;per<base;per++)if(!(now&per || now&a[0] || per&a[1] || (now&(now<<1)) || (now&(now<<2)) || (per&(per<<1)) || (per&(per<<2))))dp[now][per][1]=sum[per]+sum[now];
	for(int i=2;i<n;i++)
		for(int now=0;now<base;now++){
			if(now&a[i-1]||(now&(now<<1)) || (now&(now<<2))) continue;
			for(int per=0;per<base;per++){
				if(per&a[i] || now&per || (per&(per<<1)) || (per&(per<<2))) continue;
				for(int before=0;before<base;before++){
					if(before&now || before&per || before&a[i-2] || (before&(before<<1)) || (before&(before<<2)))continue;
					dp[now][per][i%3]=max(dp[now][per][i%3],dp[before][now][(i-1)%3]+sum[per]);	
				}
			}
		}
	for(int now=0;now<base;now++)for(int per=0;per<base;per++)ans=max(ans,dp[now][per][(n-1)%3]);
	cout<<ans;
	return 0;
}