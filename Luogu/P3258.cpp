#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn=3000005;
int vis[300005];
int n,m,r,mod,e,beg[maxn<<1],nex[maxn<<1],to[maxn<<1],a[maxn<<1],laz[maxn<<1],son[maxn<<1],id[maxn],fa[maxn<<1],cnt,dep[maxn],siz[maxn],top[maxn],res=0;
void add(int x,int y){
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
void pushdown(int rt,int lenn){
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    a[rt<<1]+=laz[rt]*(lenn-((lenn>>1)));
    a[rt<<1|1]+=laz[rt]*(lenn>>1);
    laz[rt]=0;
}
void build(int rt,int l,int r){
    if(l==r){
        a[rt]=0;
        return;
    }
    build(rt<<1,l,((l+r)>>1));
    build(rt<<1|1,((l+r)>>1)+1,r);
    a[rt]=(a[rt<<1]+a[rt<<1|1]);
}

void query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R){res+=a[rt];return;}
    if(laz[rt])pushdown(rt,(r-l+1));
    if(L<=((l+r)>>1))query(rt<<1,l,((l+r)>>1),L,R);
    if(R>((l+r)>>1))query(rt<<1|1,((l+r)>>1)+1,r,L,R);
    
}

void update(int rt,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        laz[rt]+=k;
        a[rt]+=k*(r-l+1);
    }
    else{
        if(laz[rt])pushdown(rt,(r-l+1));
        if(L<=((l+r)>>1))update(rt<<1,l,((l+r)>>1),L,R,k);
        if(R>((l+r)>>1))update(rt<<1|1,((l+r)>>1)+1,r,L,R,k);
        a[rt]=(a[rt<<1]+a[rt<<1|1]);
    }
}

int queryarea(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res=0;
        query(1,1,n,id[top[x]],id[x]);
        ans+=res;
        x=fa[top[x]];
    }
    
    if(dep[x]>dep[y])swap(x,y);
    res=0;
    query(1,1,n,id[x],id[y]);
    ans+=res;
    return ans;
}

void updatearea(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],k);
}
void dfs1(int x,int f,int deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    int maxson=-1;
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];
    }
}
void dfs2(int x,int topf){
    id[x]=++cnt;
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}

int main(){
    n=read();
    for(int i=1;i<=n;i++)vis[i]=read();
    for(int i=1;i<n;i++){
        int a,b;
        a=read();b=read();
        add(a,b);add(b,a);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    for(int i = 2;i<=n;i++){
        updatearea(vis[i-1],vis[i],1);
        updatearea(vis[i],vis[i],-1);
    }
    for(int i = 1;i<=n;i++){
        cout<<queryarea(i,i)<<endl;
    }
}