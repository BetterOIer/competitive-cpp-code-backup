#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long maxn = 1005;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
bool G[maxn][maxn];
int T,id,n,m,c,f;
long long ansC=0,ansF=0;
int dp[maxn][maxn],dp2[maxn][maxn];
long long dp3[maxn][maxn],dp4[maxn][maxn];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	for(int i = 0;i<maxn;i++){
		for(int j = 0;j<maxn;j++){
			G[i][j]=0,dp[i][j]=-1,dp2[i][j]=-1;
		}
	}
	while(T--){
		n=read(),m=read(),c=read(),f=read();
		ansC=ansF=0;
		c%=mod;f%=mod;
		string s;
		for(long long i = 1;i<=n;i++){
			cin>>s;
			for(long long j = 0;j<m;j++){
				G[i][j+1]=(s[j]=='1');
			}
		}
		//prework
		for(long long i = 1;i<=n;i++){
			for(long long j = m;j>=1;j--){
				if(G[i][j])dp[i][j]=-1;
				else dp[i][j]=dp[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;++j){
			for(int i=n;i>=1;--i){
				if(G[i][j])dp3[i][j]=0;
				else dp3[i][j]=(dp3[i+1][j]+dp[i][j])%mod;
			}
		}
		for(long long j = 1;j<=m;j++){
			for(long long i = n;i>=1;i--){
				if(G[i][j])dp2[i][j]=-1;
				else dp2[i][j]=dp2[i+1][j]+1;
			}
		}
		for(int j=1;j<=m;++j){
			for(int i=n;i>=1;--i){
				if(G[i][j])dp4[i][j]=0;
				else dp4[i][j]=(dp4[i+1][j]+(dp2[i][j]*dp[i][j])%mod)%mod;
			}
		}
		//deal cf
		for(int i=1;i<=n-2;++i){
			for(int j=1;j<=m-1;++j){
				if(dp[i][j]>=0&&dp[i+1][j]>=0){
					ansC=(ansC+dp[i][j]*dp3[i+2][j]%mod)%mod;
					ansF=(ansF+dp[i][j]*dp4[i+2][j]%mod)%mod;
				}
			}
		}
		ansC=ansC*c%mod;
		ansF=ansF*f%mod;
		cout<<ansC<<" "<<ansF<<endl;
		for(long long i = 1;i<=n;i++){
			for(long long j = 1;j<=n;j++){
				G[i][j]=0,dp[i][j]=-1,dp2[i][j]=-1,dp3[i][j]=0,dp4[i][j]=0;
			}
		}
	}
	return 0;
}