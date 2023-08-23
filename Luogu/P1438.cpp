#include<iostream>
using namespace std;
long long a[100005],cf[100005];
struct node{
    int l;
    int r;
    long long val;
    long long lazy;
}tree[600005];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline int read2(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void pushup(int pos){
    tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
}
void pushdown(int pos){
    tree[pos<<1].lazy+=tree[pos].lazy;
    tree[pos<<1|1].lazy+=tree[pos].lazy;
    tree[pos<<1].val+=(tree[pos<<1].r-tree[pos<<1].l+1)*tree[pos].lazy;
    tree[pos<<1|1].val+=(tree[pos<<1|1].r-tree[pos<<1|1].l+1)*tree[pos].lazy;
    tree[pos].lazy=0;
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r) {tree[pos].val=cf[l];return;}
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void update(int pos,int x,int y,long long D){
    int l=tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y){
        tree[pos].val+=(r-l+1)*D;
        tree[pos].lazy+=D;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(pos);
    if(mid>=x) update(pos<<1,x,y,D);
    if(mid<y) update(pos<<1|1,x,y,D);
    pushup(pos);
}
long long query(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y){
        return tree[pos].val;
    }
    int mid=(l+r)>>1;
    long long ans=0;
    pushdown(pos);
    if(mid>=x) ans+=query(pos<<1,x,y);
    if(mid<y) ans+=query(pos<<1|1,x,y);
    return ans;
}
signed main(){
    int n=read2(),m=read2(),opt,l,r;
    long long k,d;
    for(int i = 1;i<=n;i++){
        a[i]=read();
        cf[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        opt=read();
        switch (opt)
        {
        case 1:
            l=read2(),r=read2(),k=read(),d=read();
            update(1,l,l,k);
            if(l+1<=r) update(1,l+1,r,d);
            if(r<n) update(1,r+1,r+1,-(k+d*(r-l)));
            break;
        case 2:
            k=read();
            cout<<query(1,1,k)<<endl;
            break;
        default:
            break;
        }
    }
}