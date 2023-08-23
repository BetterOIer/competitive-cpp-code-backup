#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,size[100010],tot;
int head[100010],sum,root,f[100010],vis[100010],par[100010],cnt,lg[100010<<2];
long long dis1[100010],dis2[100010],sumv[100010];
struct Edge{
    int u,v,next,w;
}G[2*100010];
void Addedge(int u,int v,int w){
    G[++tot].u=u;
    G[tot].v=v;
    G[tot].w=w;
    G[tot].next=head[u];
    head[u]=tot;
}
struct TREE{
    int head[100010],cnt,tot;
    int st[100010<<2][21],dis[100010],tpos[100010<<1];
    struct edge{int u,v,next,w;}E[2*100010];
    inline void addedge(int u,int v,int w){
        E[++tot].u=u;E[tot].v=v;E[tot].w=w;E[tot].next=head[u];head[u]=tot;
        E[++tot].u=v;E[tot].v=u;E[tot].w=w;E[tot].next=head[v];head[v]=tot;
    }
    inline int getdis(int u,int v){
        if(tpos[u]>tpos[v])swap(u,v);
        int k=lg[tpos[v]-tpos[u]+1];
        return dis[u]+dis[v]-2*min(st[tpos[u]][k],st[tpos[v]-(1<<k)+1][k]);
    }
    void dfs(int u,int fa){
        st[++cnt][0]=dis[u];tpos[u]=cnt;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].v;if(v==fa)continue;
            dis[v]=dis[u]+E[i].w;
            dfs(v,u);
            st[++cnt][0]=dis[u];
        }
    }
    inline void initrmq(){
        memset(tpos,0,sizeof(tpos));cnt=0;tot=0;dis[1]=0;
        dfs(1,0);
        for(int j=1;(1<<j)<=cnt;j++)
        for(int i=1;i+(1<<j)-1<=cnt&&i<=cnt;i++)
        st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}T;
void getroot(int u,int fa){
    size[u]=1;f[u]=0;
    for(int i=T.head[u];i;i=T.E[i].next){
        int v=T.E[i].v;if(vis[v]||v==fa)continue;
        getroot(v,u);size[u]+=size[v];
        f[u]=max(f[u],size[v]);
    }
    f[u]=max(f[u],sum-size[u]);
    if(f[u]<f[root])root=u;
}
void work(int u,int fa){
    vis[u]=1;par[u]=fa;
    for(int i=T.head[u];i;i=T.E[i].next){
        int v=T.E[i].v;if(vis[v])continue;
        sum=size[v];f[0]=size[v];root=0;
        getroot(v,0);Addedge(u,root,v);
        work(root,u);
    }
}
inline void insert(int u,int val){
    sumv[u]+=val;
    for(int i=u;par[i];i=par[i]){
        int dist=T.getdis(par[i],u);
        dis1[par[i]]+=(long long)dist*val;
        dis2[i]+=(long long)dist*val;
        sumv[par[i]]+=val;
    }
}
inline long long calc(int u){
    long long ans=dis1[u];
    for(int i=u;par[i];i=par[i]){
        int dist=T.getdis(par[i],u);
        ans+=dis1[par[i]]-dis2[i];
        ans+=dist*(sumv[par[i]]-sumv[i]);
    }
    return ans;
}
long long query(int u){
    long long ans=calc(u);
    for(int i=head[u];i;i=G[i].next){
        long long tmp=calc(G[i].w);
        if(tmp<ans)return query(G[i].v);
    }
    return ans;
}
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
void init(){
    memset(dis1,0,sizeof(dis1));
    memset(dis2,0,sizeof(dis2));
    memset(sumv,0,sizeof(sumv));
    lg[0]=-1;
    for (int i=1;i<(100010<<2);i++)lg[i]=lg[i>>1]+1;
    n=read();m=read();
    for (int i=1;i<n;i++)
    x=read(),y=read(),z=read(),T.addedge(x,y,z);
}
int main(){
    init();T.initrmq();sum=n;f[0]=n;
    root=0;getroot(1,0);
    int LastOrder=root;work(root,0);root=LastOrder;
    
    for(int i=1;i<=m;i++){
        x=read();y=read();insert(x,y);
        printf("%lld\n",query(root));
    }
    return 0;
}
