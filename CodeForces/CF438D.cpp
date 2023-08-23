#include<iostream>
using namespace std;
struct node{
    int l;
    int r;
    long long val;
    long long mxv;
    long long lazy;
}tree[400005];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void pushup(int pos){
    tree[pos].val=(tree[pos<<1].val+tree[pos<<1|1].val);
    tree[pos].mxv=max(tree[pos<<1].mxv,tree[pos<<1|1].mxv);
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
void update_mod(int pos,int x,int y,int data){
    if(data>tree[pos].mxv)return;
    int l = tree[pos].l,r=tree[pos].r;
    if(l==r){
        tree[pos].val = tree[pos].val%data;
        tree[pos].mxv = tree[pos].val;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update_mod(pos<<1,x,y,data);
    if(mid<y) update_mod(pos<<1|1,x,y,data);
    pushup(pos);
}
long long query(int x,int y,int pos){
    int l = tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y) return tree[pos].val;
    pushdown(pos);
    int mid=(l+r)>>1;
    long long ans=0;
    if(mid>=x) ans=ans+query(x,y,pos<<1);
    if(mid<y) ans=ans+query(x,y,pos<<1|1);
    return ans;
}
void updatepoint(int pos,int x,int data){
    if(tree[pos].l==x&&tree[pos].r==x){
        tree[pos].val=data;
        tree[pos].mxv=tree[pos].val;
        return;
    }
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid<x) updatepoint(pos<<1|1,x,data);
    else updatepoint(pos<<1,x,data);
    pushup(pos);
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r) {
        tree[pos].val=read();
        tree[pos].mxv=tree[pos].val;
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
int main(){
    int n,m,opt,x,y,k;
    cin>>n>>m;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        cin>>opt;
        if(opt==1){
            cin>>x>>y;
            cout<<query(x,y,1)<<endl;
        }else if(opt==2){
            cin>>x>>y>>k;
            update_mod(1,x,y,k);
        }else{
            cin>>x>>y;
            updatepoint(1,x,y);
        }
    }
}