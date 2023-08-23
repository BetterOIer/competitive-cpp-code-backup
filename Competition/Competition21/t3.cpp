#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int nxt[1<<10][11];
int dp[1005][1<<10];
int L[1005];
void init(){
	for(int i=0;i<1024;i++)
		for(int j=0;j<10;j++)
			for(int k=j;k<10;k++)
				if(i&(1<<k)){nxt[i][j]=1<<k;break;}
}
int main(){
	init();
	int T;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&L[i]);
		memset(dp[i],0,sizeof(dp[i]));
	}
	if(n==1){
		puts("10");
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<1024;j++){
			if(!dp[i-1][j])continue;
			for(int ct=0,k=0;k<10;k++){
				if(ct==L[i]-1&&(i>1||k>0))
					(dp[i][(j^nxt[j][k])|(1<<k)]+=dp[i-1][j])%=P;
				if(j&(1<<k))ct++;
				if(ct==L[i])break;
			}
		}
	}
	int ans=0;
	for(int i=0;i<1024;i++)
		(ans+=dp[n][i])%=P;
	printf("%d\n",ans);
	return 0;
}
