#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,tot=0,tcnt=0;
const int maxn = 200005;
int a[maxn],b[maxn<<1],root[maxn];
struct node{
    int l;
    int r;
    int val=0;
}tree[maxn*25];
void build(int &pos, int l,int r){
    if(l==r)return;
    int mid = (l+r)>>1;
    tree[pos].l=++tcnt;
    tree[pos].r=++tcnt;
    build(tree[pos].l,l,mid);build(tree[pos].r,mid+1,r);
}
void update(int &pos,int pre, int l,int r,int x,int val){
    if(l==r){
        tree[pos].val=val;
        return;
    }
    int mid = (l+r)>>1;
    if(x<=mid){
        tree[pos].l=++tcnt;
        update(tree[pos].l,tree[pre].l,l,mid,x,val);
        tree[pos].r=tree[pre].r;
    }else{
        tree[pos].r=++tcnt;
        update(tree[pos].r,tree[pos].r,mid+1,r,x,val);
        tree[pos].l=tree[pre].l;
    }
    tree[pos].val=min(tree[tree[pos].l].val,tree[tree[pos].r].val);
}
int query(int pos,int l,int r,int val){
    if(l==r)return l;
    int mid = (l+r)>>1;
    if(tree[tree[pos].l].val<val) return query(tree[pos].l,l,mid,val);
    return query(tree[pos].r,mid+1,r,val);
}
int main(){
    freopen("P4137_1.in","r",stdin);
    freopen("P4137_1.out","w",stdout);
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        b[++tot]=a[i];
        b[++tot]=a[i]+1;
    }
    b[++tot]=0;
    sort(b+1,b+tot+1);
    tot = unique(b+1,b+tot+1)-b-1;
    root[0]=++tcnt;
    build(root[0],1,tot);
    for(int i = 1;i<=n;i++){
        root[i]=++tcnt;
        update(root[i],root[i-1],1,tot,lower_bound(b+1,b+tot+1,a[i])-b,i);
    }
    for(int i = 1,l,r;i<=m;i++){
        l=read(),r=read();
        printf("%d\n",b[query(root[r],1,tot,l)]);
    }
}