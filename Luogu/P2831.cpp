#include<bits/stdc++.h>
using namespace std;
struct node{
	double x,y;
}pi[20];
int st[20][20],vis[20],t,n,m,dp[262244];
int dps(int d1,int d2) {
	double x1=pi[d1].x,y1=pi[d1].y;
	double x2=pi[d2].x,y2=pi[d2].y;
	if(x1==x2)return 0;
	double tx=x1*x1*x2-x2*x2*x1,ty=y1*x2-y2*x1;
	double a=ty/tx,b=(y1-a*x1*x1)/x1;
	if(a>=0)return 0;
	int ans=0;
	vis[d1]=vis[d2]=1;
	for(int i=1;i<=n;++i) {
		double x=pi[i].x,y=pi[i].y;
		if(fabs(a*x*x+b*x-y)<1e-7) {
			ans|=1<<(i-1);
			dp[1<<(i-1)]=dp[ans]=1;
		}
	}
	return ans;
}
int main() {
	cin>>t;
	while(t--) {
		memset(dp,0x3f,sizeof(dp));
		memset(vis,0,sizeof(vis));
		cin>>n>>m; 
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&pi[i].x,&pi[i].y);
			dp[1<<(i-1)]=1;
		}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<i;j++)
				st[i][j]=dps(i,j);
		for(int i=1;i<=(1<<n)-1;++i){
			for(int j=1;j<=n;++j){
				if(((i>>(j-1))&1)==1)continue;
				for(int k=1;k<=j;++k){
					if((i&(1<<(k-1)))==1)continue;
					dp[i|st[j][k]]=min(dp[i|st[j][k]],dp[i]+1);
                }
				dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1);
				
			}
		} 
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}

