#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#define inf 0x3f3f3f3f
#define int long long
#define p 1000000007
using namespace std;

int dp[62][10002];

inline int power(int a,int t);
int inv(int n);
int solve(int a,int i,int j);

signed main(){
	int n,k,t,ans = 1;
	scanf("%lld%lld",&n,&k);
	for(int i=2;i*i<=n;++i){
		if(n%i!=0) continue; //不是因数,跳过 
		cout<<i<<" ";
		t = 0;
		while(n%i==0){
			++t;
			n /= i; //找到质因数,算幂次 
		}
		memset(dp,0,sizeof(dp));
		ans = (ans*solve(i,t,k))%p;
	}
	memset(dp,0,sizeof(dp));
	cout<<n<<" ";
	if(n>1) ans = (ans*solve(n,1,k))%p; //最后可能剩下n>1,需要多算一遍 
	printf("%lld",ans);
	return 0;
}

inline int power(int a,int t){
	int res = 1;
	while(t){
		if(t&1) res = res*a%p;
		a = a*a%p;
		t >>= 1;
	}
	return res;
}

int inv(int n){
	return power(n,1000000005);
}

int solve(int a,int i,int j){
	if(i==0){
		dp[i][j] = 1; //p^0为1,经过多少次操作还是1 
		return 1;
	}
	if(j==0){
		//0次操作的情况，即为原数 
		if(dp[i][j]==0) dp[i][j] = solve(a,i-1,j)*a%p;
		return dp[i][j];
	}
	int ans = 0;
	for(int k=0;k<=i;++k){
    	//套用上面的式子
		if(dp[k][j-1]==0) dp[k][j-1] = solve(a,k,j-1);
		ans = (ans+dp[k][j-1])%p;
	}
	return ans*inv(i+1)%p;
}
