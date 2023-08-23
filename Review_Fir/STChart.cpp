/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int dep[500005],fa[500005][22];
vector<int> ro[500005];
void dfs(int now,int father){
    dep[now]=dep[father]+1;
    fa[now][0]=father;
    for(int i = 1;i<=19;i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
    }
    for(int to:ro[now]){
        if(to == father) continue;
        dfs(to,now);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i = 19;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    }
    if(u==v) return v;
    for(int i = 19;i>=0;i--){
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
int n,m,s;
int main(){
    n=read(),m=read(),s=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    dfs(s,0);
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        cout<<lca(u,v)<<endl;
    }
    return 0;
}