#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,y,A[2][45];
long long dp[2][45];
int main()
{
	scanf("%d %d",&n,&m);
	memset(A,0,sizeof(A));
	memset(dp,0,sizeof(dp));
	while(n--)
	{
		scanf("%d %d",&x,&y);	
		A[0][x]+=1;
		A[1][x]+=y;
	}
	dp[0][0]=1;
	for(int color=0,i=1;i<41;i++)
		if(A[0][i]){
			color++;
			long long s=(1ll<<A[0][i])-1,p=(1ll<<(A[0][i]-1))*A[1][i];
			for(int j=color;j>0;j--)
			{
				dp[0][j]+=dp[0][j-1]*s;
				dp[1][j]+=dp[0][j-1]*p+dp[1][j-1]*s;
			}
		}
	long long cost=0;
	for(int i=m;i<41;i++)
	{
		cost+=dp[1][i];
	}
	printf("%lld\n",cost);
	return 0;
}
