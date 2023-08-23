/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn =1005;
int dp[maxn][maxn],cost[maxn],bin[maxn][maxn],cnt[maxn];
int n,k,p,h,ans,g=1;
void cal(int whi){
	bin[whi][1]+=cost[whi];
	for(int j=2;j<=cnt[whi];j++){
		bin[whi][j]+=bin[whi][j-1];
	}
}
int main(){
	n=read(),k=read(),p=read();
	for(int i=1;i<=k;i++)cost[i]=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read();
		bin[y][++cnt[y]]=x;
	}
	for(int i=1;i<=k;i++)sort(bin[i]+1,bin[i]+cnt[i]+1);
	for(int i=1;i<=k;i++)cal(i);
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int i = 0;i<maxn;i++){
		for(int j = 1;j<maxn;j++){
			dp[i][j]=2000000000;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=cnt[i];j++,g++){
			for(int l=0;l<=ans+j;l++){	
				ans++;
				if(l>=j)dp[g][l]=min(dp[h][l-j]+bin[i][j],dp[h][l]);
				dp[g][l]=min(dp[g-1][l],dp[g][l]);
				if(dp[g][l]>p){
					ans=l-1;
					break;
				}
			}
		}
		h+=cnt[i];
	}
	for(int i=n;i>=1;i--){
		if(dp[n][i]<=p){
			cout<<i<<endl;
			return 0;
		}
	}
}