/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
且将新火试新茶，诗酒趁年华 --来自网络
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,T;
double p,dp[2005][2005];
int main(){
    n=read();scanf("%lf",&p);T=read();
    dp[0][0] = 1.0;
    for(int i=1;i<=T;++i)
		for(int j=0;j<=n;++j) {
			if(j == 0) dp[i][j] = dp[i-1][j]*(1-p);	
			if(j == n) dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*p;
			else dp[i][j] = dp[i-1][j]*(1-p) + dp[i-1][j-1]*p;
		}
    double ans = 0.0;
    for(int i=1;i<=n;++i)
		ans += dp[T][i] *i;
    printf("%lf",ans);
}