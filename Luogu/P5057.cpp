#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int l;
    int r;
    int val;
    int lazy;
}tree[900000];
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
void update(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y){
        tree[pos].val+=(r-l+1);
        tree[pos].lazy++;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(pos);
    if(mid>=x){
        update(pos<<1,x,y);
    }if(mid<y){
        update(pos<<1|1,x,y);
    }
    pushup(pos);
}
int query(int pos,int po){
    int l=tree[pos].l,r=tree[pos].r;
    if(l==r) return tree[pos].val&1;
    pushdown(pos);
    int mid=(l+r)>>1;
    if(mid<po){
        return query(pos<<1|1,po);
    }else{
        return query(pos<<1,po);
    }
}
void build(int pos,int l,int r){
    tree[pos].l=l;
    tree[pos].r=r;
    if(l==r){
        tree[pos].val=0;
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
int main(){
    int opt,a,b,n=read(),m=read();
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        opt=read(),a=read();
        if(opt==1){
            b=read();
            update(1,a,b);
        }else{
            cout<<query(1,a)<<endl;
        }
    }
}