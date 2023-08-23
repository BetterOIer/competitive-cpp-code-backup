#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a[1001][1001];
long long shang[1005],xia[1005],dp[1005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	dp[1]=a[1][1];
	for(int i=2;i<=n;i++) dp[i]=dp[i-1]+a[i][1];
	for(int j=2;j<m;j++){
		memset(xia,0,sizeof(xia));
		memset(shang,0,sizeof(shang));
		xia[1]=dp[1]+a[1][j];shang[n]=dp[n]+a[n][j];
		for(int i=2;i<=n;i++) xia[i]=max(dp[i],xia[i-1])+a[i][j];
		for(int i=n-1;i>=1;i--) shang[i]=max(dp[i],shang[i+1])+a[i][j];
		for(int i=1;i<=n;i++) dp[i]=max(xia[i],shang[i]);
	}
	dp[1]+=a[1][m];
	for(int i=2;i<=n;i++) dp[i]=max(dp[i],dp[i-1])+a[i][m];
	printf("%lld",dp[n]);
	return 0;
}
