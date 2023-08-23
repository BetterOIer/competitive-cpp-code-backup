#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m;
vector<int>f[300005];
bool vis[300005];
void dfs(int x){
    if(vis[x]||x==n)return;
    vis[x]=1;
    for(int y:f[x]){
        dfs(y);
    }
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        f[u].push_back(v),f[v].push_back(u);
    }
    dfs(n-1);
    for(int i=1;i<=n;i++){
        if(vis[i])putchar('B');
        else putchar('A');
    }
}