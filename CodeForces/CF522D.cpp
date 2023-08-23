#include<iostream>
#include<map>
using namespace std;
#define mid ((l+r)>>1)
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
struct node{
    int l;
    int r;
    int v=2147483647;
}tree[15000006];
int n,m,cnt;
int a[500005],pos[500005];
map<int,int>f;
void pushup(int pos){
    tree[pos].v=min(tree[tree[pos].l].v,tree[tree[pos].r].v);
}
void update(int &pos,int l,int r,int x,int v){
    tree[++cnt]=tree[pos],pos=cnt;
    if(l==r)return (void)(tree[pos].v=v);
    (mid>=x? update(tree[pos].l,l,mid,x,v):update(tree[pos].r,mid+1,r,x,v));
    pushup(pos);
}
int query(int pos,int l,int r,int x,int y){
    if(l>=x&&r<=y)return tree[pos].v;
    int ans=2147483647;
    if(mid>=x)ans=min(ans,query(tree[pos].l,l,mid,x,y));
    if(mid<y)ans=min(ans,query(tree[pos].r,mid+1,r,x,y));
    return ans;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pos[i]=pos[i-1];
        if(!f[a[i]])f[a[i]]=i;
        else update(pos[i],1,n,f[a[i]],i-f[a[i]]),f[a[i]]=i;
    }
    while(m--){
        int l=read(),r=read();
        int ans=query(pos[r],1,n,l,r);
        printf("%d\n",ans==2147483647?-1:ans);
    }
    return 0;
}