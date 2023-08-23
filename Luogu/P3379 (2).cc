#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2*1e6+10;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int u,v,nxt;
}edge[MAXN];
int head[MAXN];
int num=1;
struct TREE{
    int l,r,w,siz,f;
}Tree[MAXN];
int N,M,root,MOD,cnt=0,a[MAXN],b[MAXN];

inline void Add(int x,int y){
    edge[num].u=x;
    edge[num].v=y;
    edge[num].nxt=head[x];
    head[x]=num++;
}

int deep[MAXN],fa[MAXN],son[MAXN],tot[MAXN],top[MAXN],idx[MAXN];

int dfs1(int now,int f,int dep){
    deep[now]=dep;
    fa[now]=f;
    tot[now]=1;
    int maxson=-1;
    for(int i=head[now];i!=-1;i=edge[i].nxt){
        if(edge[i].v==f) continue;
        tot[now]+=dfs1(edge[i].v,now,dep+1);
        if(tot[edge[i].v]>maxson) maxson=tot[edge[i].v],son[now]=edge[i].v;
    }
    return tot[now];
}
void update(int k){
    Tree[k].w=(Tree[k<<1].w+Tree[k<<1|1].w+MOD)%MOD;
}
void Build(int k,int ll,int rr){
    Tree[k].l=ll;Tree[k].r=rr;Tree[k].siz=rr-ll+1;
    if(ll==rr){
        Tree[k].w=a[ll];
        return ;
    }
    int mid=(ll+rr)>>1;
    Build(k<<1,ll,mid);
    Build(k<<1|1,mid+1,rr);
    update(k);
}
void dfs2(int now,int topf){
    idx[now]=++cnt;
    a[cnt]=b[now];
    top[now]=topf;
    if(!son[now]) return ;
    dfs2(son[now],topf);
    for(int i=head[now];i!=-1;i=edge[i].nxt) if(!idx[edge[i].v]) dfs2(edge[i].v,edge[i].v);
}
void pushdown(int k)
{
    if(!Tree[k].f) return ;
    Tree[k<<1].w=(Tree[k<<1].w+Tree[k<<1].siz*Tree[k].f)%MOD;
    Tree[k<<1|1].w=(Tree[k<<1|1].w+Tree[k<<1|1].siz*Tree[k].f)%MOD;
    Tree[k<<1].f=(Tree[k<<1].f+Tree[k].f)%MOD;
    Tree[k<<1|1].f=(Tree[k<<1|1].f+Tree[k].f)%MOD;
    Tree[k].f=0;
}
void IntervalAdd(int k,int ll,int rr,int val){
    if(ll<=Tree[k].l&&Tree[k].r<=rr){
        Tree[k].w+=Tree[k].siz*val;
        Tree[k].f+=val;
        return ;
    }
    pushdown(k);
    int mid=(Tree[k].l+Tree[k].r)>>1;
    if(ll<=mid) IntervalAdd(k<<1,ll,rr,val);
    if(rr>mid) IntervalAdd(k<<1|1,ll,rr,val);
    update(k);
}
void TreeAdd(int x,int y,int val){
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        IntervalAdd(1,idx[ top[x] ],idx[x],val);
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y])    swap(x,y);
    IntervalAdd(1,idx[x],idx[y],val);
}
int IntervalSum(int k,int ll,int rr){
    int ans=0;
    if(ll<=Tree[k].l&&Tree[k].r<=rr) return Tree[k].w;
    pushdown(k);
    int mid=(Tree[k].l+Tree[k].r)>>1;
    if(ll<=mid) ans=(ans+IntervalSum(k<<1,ll,rr))%MOD;
    if(rr>mid)  ans=(ans+IntervalSum(k<<1|1,ll,rr))%MOD;
    return ans;
}
void TreeSum(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        ans=(ans+IntervalSum(1,idx[ top[x] ],idx[x]))%MOD;
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y]) swap(x,y);
    ans=(ans+IntervalSum(1,idx[x],idx[y]))%MOD;
    printf("%d\n",ans);
}
int main(){
    memset(head,-1,sizeof(head));
    N=read(),M=read(),root=read(),MOD=read();
    for(int i=1;i<=N;i++) b[i]=read();
    for(int i=1;i<=N-1;i++){
        int x=read(),y=read();
        Add(x,y),Add(y,x);
    }
    dfs1(root,0,1);
    dfs2(root,root);
    Build(1,1,N);
    while(M--){
        int opt=read(),x=read(),y,z;
        if(opt==1) y=read(),z=read(),z=z%MOD,TreeAdd(x,y,z);
        else if(opt==2) y=read(),TreeSum(x,y);
        else if(opt==3) z=read(),IntervalAdd(1,idx[x],idx[x]+tot[x]-1,z%MOD);
        else if(opt==4) printf("%d\n",IntervalSum(1,idx[x],idx[x]+tot[x]-1));
    }
    return 0;
}
