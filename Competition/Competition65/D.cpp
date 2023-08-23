/*=================================================
* Le vent se lève,il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,t[3005],a[3005],p;
long long dp[3005][104],ans;
inline long long sol(int l,int r){
	return ((long long)(r-l-1)*(r-l)>>1)*max(a[l],a[r])+a[r]*a[r];
}
int main(){
    n=read(),m=read();
    memset(dp,0x3f3f3f,sizeof dp),dp[1][1]=0,ans=9223372036854775807ll;
	for(int i=0;i<n;i++)t[i]=read(),t[i]||(p=i);
	for(int i=0;i<n;i++)a[i+1]=t[(i+p)%n];
	for(int i=1;i<=n;i++)for(int j=2;j<=min(i,m);j++)for(int k=1;k<i;k++){
		dp[i][j]=min(dp[i][j],dp[k][j-1]+sol(k,i));
		if(j==m)dp[i][j]=min(dp[i][j],dp[k][j]+sol(k,i));
	}
	for(int i=1;i<=n;i++)ans=min(ans,dp[i][m]+sol(i,n+1));
	printf("%lld",ans);
}
