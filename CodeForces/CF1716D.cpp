#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod = 998244353;
int n,k;
int dp[200005],ans[200005];
int main(){
    n=read(),k=read();
    dp[0]=1;
    for(int w=k,x=0;x<=n;w++,x+=w){
        for(int i = n;i>=w;i--) dp[i]=dp[i-w];
        for(int i = w-1;~i;i--) dp[i]=0;
        for(int i = x;i<=n;i++) dp[i]=(dp[i-w]+dp[i])%mod;
        for(int i = 1;i<=n;i++) ans[i]=(ans[i]+dp[i])%mod;
    }
    for(int i = 1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}