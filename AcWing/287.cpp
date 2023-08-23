#include<vector>
#include<iostream>
using namespace std;
bool vis[200005],vis1[200005];
long long dp[200005],G[200005];;
int deg[200005];
struct node{
    int to;
    long long val;
};
vector<node>tree[200005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n;
void tdp(int pos){
    vis[pos]=true;
    dp[pos]=0;
    for(node i:tree[pos]){
        if(vis[i.to])continue;
        tdp(i.to);
        if(deg[i.to]==1)dp[pos]+=i.val;
        else dp[pos]+=min(dp[i.to],i.val);
    }
}
void dfs(int pos){
    vis1[pos]=true;
    for(node i:tree[pos]){
        if(vis1[i.to])continue;
        if(deg[pos]>1&&deg[i.to]>1) G[i.to]=dp[i.to]+min(G[pos]-min(dp[i.to],i.val),i.val);
        else if(deg[i.to]==1) G[i.to]=dp[i.to]+min(dp[pos]-i.val,i.val);
        else if(deg[pos]==1) G[i.to]=dp[i.to]+i.val;
        dfs(i.to);
    }
}
int main(){
    int t=read();
    while(t--){
        n=read();
        for(int i = 1,u,v,w;i<n;i++){
            u=read(),v=read(),w=read();
            deg[u]++,deg[v]++;
            tree[u].push_back((node){v,w});
            tree[v].push_back((node){u,w});
        }
        tdp(1);
        G[1]=dp[1];
        dfs(1);
        long long ans=0;
        for(int i = 1;i<=n;i++)ans=max(G[i],ans);
        cout<<ans<<endl;
        for(int i = 1;i<=n;i++) G[i]=0;
        for(int i = 1;i<=n;i++) dp[i]=0;
        for(int i = 1;i<=n;i++) vis1[i]=0;
        for(int i = 1;i<=n;i++) vis[i]=0;
        for(int i = 1;i<=n;i++) deg[i]=0;
        for(int i = 1;i<=n;i++) tree[i].clear();
    }
}