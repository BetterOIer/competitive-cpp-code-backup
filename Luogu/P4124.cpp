#include<iostream>
#include<cstring>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long dp[12][11][11][2][2][2][2];
long long a[12];
long long L, R;
long long dfs(long long pos,long long pre1,long long pre2,long long lim,long long same3,long long apr8,long long apr4){
    if(apr8&&apr4)return 0;
    if(pos==0)return same3;
    if(~dp[pos][pre1][pre2][lim][same3][apr8][apr4])return dp[pos][pre1][pre2][lim][same3][apr8][apr4];
    long long res=0,maxn = lim*a[pos]+(!lim)*9;
    for(long long i = 0;i<=maxn;i++){
        res+=dfs(pos-1,i,pre1,lim&&(i==a[pos]),(same3||((pre1==pre2)&&(pre2==i))),(i==8)||apr8,(i==4)||apr4);
    }
    return dp[pos][pre1][pre2][lim][same3][apr8][apr4]=res;
}
long long solve(long long x){
    if(x<1e10) return 0;
    memset(dp,-1,sizeof dp);
    long long len=0,res=0;
    while(x){
        a[++len]=x%10;
        x/=10;
    }
    for(long long i=1;i<=a[len];i++){
        res+=dfs(len-1,i,-1,i==a[len],0,i==8,i==4);
    }
    return res;
}
int main(){
    L=read(),R=read();
    cout<<solve(R)-solve(L-1);
}