#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x;
}
ll dp[11][64][1<<11];
int mod,A[64],T;
ll dfs(int len,int lim,int lead,int jinzhi){
    if(!len)return (jinzhi==0);
    if(~dp[mod][len][jinzhi]&&!lim&&!lead)return dp[mod][len][jinzhi];
    ll ans=0;
    int maxx=(lim?A[len]:mod-1);
    for(int i=0;i<=maxx;i++){
        int jinzhit;
        if(i==0&&lead)jinzhit=jinzhi;
        else jinzhit=jinzhi^(1<<i);
        ans+=dfs(len-1,lim&(i==maxx),lead&(i==0),jinzhit);
    }
    if(lim|lead)return ans;
    return dp[mod][len][jinzhi]=ans;
}
inline ll solve(ll x){
    int len=0;
    
    while(x){
        A[++len]=x%mod;
        x/=mod;
    }
    return dfs(len,1,1,0);
}
int main(){
    T=read();memset(dp,-1,sizeof(dp));
    while(T--){
        mod=read();
        ll a=read(),b=read();
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}