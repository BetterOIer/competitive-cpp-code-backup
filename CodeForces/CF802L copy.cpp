/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
    int val;
};
vector<node>ro[100005];
int n,dp[100005],dg[100005];
inline int qpow(int a,int b){int res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
int dfs(int pos,int fa){
    if(ro[pos].size()==1)return dp[pos]=1;
    int up=0;
    for(node to:ro[pos]){
        if(to.to==fa){
            up=(up+to.val)%mod;
            continue;
        }
        dfs(to.to,pos);
        up=(up+dp[to.to]+to.val)%mod;
    }
    return dp[pos]=up*qpow(ro[pos].size(),mod-2)%mod;
}
int main(){
    n=read();
    for(int i = 1,u,v,w;i<n;i++){
        u=read()+1,v=read()+1,w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
        dg[u]++,dg[v]++;
    }
    dfs(1,0);
    printf("%d\n",dp[1]);
}