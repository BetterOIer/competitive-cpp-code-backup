#include<iostream>
using namespace std;
long long n;
long long dp[35][35], tree[35][35];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void print(long long l, long long r){
	if(l > r)return;
	printf("%lld ",tree[l][r]);
	if(l == r)return;
	print(l, tree[l][r]-1);
	print(tree[l][r]+1,r);
}
int main(){
	n=read();
	for(long long i = 1;i<= n;i++)dp[i][i]=read(),dp[i][i-1]=1, tree[i][i] = i;
	for(long long len = 1;len< n;++len){
		for(long long i = 1;i+len<= n;++i){
			long long j = i+len;
			dp[i][j] = dp[i+1][j]+dp[i][i];
			tree[i][j] = i;
			for(long long k = i+1;k< j;++k){
				if(dp[i][j]< dp[i][k-1] * dp[k+1][j]+dp[k][k]){
					dp[i][j] = dp[i][k-1] * dp[k+1][j]+dp[k][k];
					tree[i][j] = k;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	print(1, n);
	return 0;
}