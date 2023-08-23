#include<iostream>
#include<cstring>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long a[14];
long long dp[14][14][2][2],cnt;
long long dfs(long long pos,long long all,long long lim,long long lead){
    if (pos==0)return all;
	if (~dp[pos][all][lim][lead])return dp[pos][all][lim][lead];
	long long res=0,maxn=lim*a[pos]+(!lim)*9;
	for(long long i = 0;i<=maxn;i++){
		res+=dfs(pos-1,((!cnt)? (all+((!lead)&&(i==0))):(all+(cnt==i))),lim&(i==maxn),lead&(i==0));
	}
	return dp[pos][all][lim][lead]=res;
}
long long solve(long long x){
	long long len = 0;
	memset(dp,-1,sizeof dp);
	while(x){
		a[++len]=x%10;
		x/=10;
	}
	return dfs(len,0,1,1);
}
int main(){
    long long a=read();
    long long b=read();
    for(cnt=0;cnt<=9;cnt++){
		cout<<solve(b)-solve(a-1)<<" ";
	}
}