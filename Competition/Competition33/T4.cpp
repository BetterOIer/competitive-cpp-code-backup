#include<iostream>
using namespace std;
int a[100005];
struct node{
    int l;
    int r;
    long long val;
    int lazy;
}tree[6000005];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void pushup(int pos){
    tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
}
void pushdown(int pos){
    if(tree[pos].lazy){
        tree[pos<<1].val+=tree[pos].lazy*(tree[pos<<1].r-tree[pos<<1].l+1);
        tree[pos<<1|1].val+=tree[pos].lazy*(tree[pos<<1|1].r-tree[pos<<1|1].l+1);
        tree[pos<<1].lazy+=tree[pos].lazy;
        tree[pos<<1|1].lazy+=tree[pos].lazy;
        tree[pos].lazy=0;
    }
    return;
}
void update(int pos,int x,int data){
    if(tree[pos].l==x&&tree[pos].r==x) tree[pos].val=data;
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid<x) update(pos<<1|1,x,data);
    else update(pos<<1,x,data);
    pushup(pos);
}
long long query(int x,int y,int pos){
    pushdown(pos);
    if(x<=tree[pos].l&&y>=tree[pos].r) return tree[pos].val;
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=0;
    if(mid>=x)ans+=query(x,y,pos<<1);
    if(mid<y)ans+=query(x,y,pos<<1|1);
    return ans;
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        tree[pos].val=read();
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
    return;
}
int main(){
    int n=read(),m=read(),opt,x,y,k=read();
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        cin>>opt;
        if(opt==1){
            cin>>x>>y;
            update(1,x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(x,y,1)<<endl;
        }
    }
}