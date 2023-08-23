#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<iostream>  
#define MAXN 10005 
#define INF 999999999
using namespace std; 
struct Edge1{  
    int x,y,dis;
}edge1[50005];
struct Edge2{
    int to,next,w;
}edge2[100005];
int cnt,n,m,head[MAXN],deep[MAXN],f[MAXN],fa[MAXN][21],w[MAXN][21]; 
bool vis[MAXN]; 
void addedge(int from, int to, int w){
    edge2[++cnt].next=head[from];
    edge2[cnt].to=to;
    edge2[cnt].w=w;
    head[from]=cnt;
    return ;
}
bool CMP(Edge1 x, Edge1 y){
    return x.dis>y.dis;
}
int find(int x){ 
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void kruskal(){
    sort(edge1+1, edge1+m+1, CMP); 
    for(int i=1; i<=n; i++)
        f[i]=i; 
    for(int i=1; i<=m; i++)
        if(find(edge1[i].x)!=find(edge1[i].y)){
            f[find(edge1[i].x)]=find(edge1[i].y);
            addedge(edge1[i].x, edge1[i].y, edge1[i].dis);
            addedge(edge1[i].y, edge1[i].x, edge1[i].dis); 
        }
    return ;
}
void dfs(int node){
    vis[node]=true;
    for(int i=head[node]; i; i=edge2[i].next){
        int to=edge2[i].to;
        if(vis[to]) continue;
        deep[to]=deep[node]+1;
        fa[to][0]=node;
        w[to][0]=edge2[i].w;
        dfs(to);
    }
    return ;
}
int lca(int x, int y){
    if(find(x)!=find(y)) return -1;
    int ans=INF;
    if(deep[x]>deep[y]) swap(x,y);
    for(int i=20; i>=0; i--)
        if(deep[fa[y][i]]>=deep[x]){
            ans=min(ans, w[y][i]); 
            y=fa[y][i];
        }
    if(x==y) return ans;
    for(int i=20; i>=0; i--)
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans, min(w[x][i], w[y][i]));
            x=fa[x][i]; 
            y=fa[y][i];
        }
    ans=min(ans, min(w[x][0], w[y][0]));
    return ans;
}
int main(){
    int x,y,z,q;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++){
        scanf("%d%d%d",&x,&y,&z);
        edge1[i].x=x;
        edge1[i].y=y;
        edge1[i].dis=z;
    }
    kruskal();
    for(int i=1; i<=n; i++)
        if(!vis[i]){
            deep[i]=1; 
            dfs(i);
            fa[i][0]=i;
            w[i][0]=INF;
        }
    for(int i=1; i<=20; i++)
        for(int j=1; j<=n; j++){
            fa[j][i]=fa[fa[j][i-1]][i-1]; 
            w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);
        }
    scanf("%d",&q);
    for(int i=1; i<=q; i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
} 
/*
            .-/+oossssoo+/-.
        `:+ssssssssssssssssss+:`
      -+ssssssssssssssssssyyssss+-
    .ossssssssssssssssssdMMMNysssso.
   /ssssssssssshdmmNNmmyNMMMMhssssss/
  +ssssssssshmydMMMMMMMNddddyssssssss+
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
+sssshhhyNMMNyss Nbest sssyNMMMysssssss+
ossyNMMMNyMMhsss Nbest sssshmmmhssssssso 
ossyNMMMNyMMhsss Nbest sssshmmmhssssssso 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+ 
.ssssssssdMMMNhsssssssssshNMMMdssssssss. 
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/
  +sssssssssdmydMMMMMMMMddddyssssssss+
   /ssssssssssshdmNNNNmyNMMMMhssssss/
    .ossssssssssssssssssdMMMNysssso.
      -+sssssssssssssssssyyyssss+-
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.
 */