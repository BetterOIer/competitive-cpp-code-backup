#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int l,r,lazy;
    long long val;
}tree[800005];
void pushup(int pos){
    tree[pos].val=max(tree[pos<<1].val,tree[pos<<1|1].val);
}

void update(int pos,int po,long long val){
    int l=tree[pos].l,r=tree[pos].r;
    if(l==r){
        tree[pos].val=max(val,tree[pos].val);
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=po)update(pos<<1,po,val);
    else update(pos<<1|1,po,val);
    pushup(pos);
}
long long query(int pos,int x,int y){
    long long ans=0;
    int l=tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y)return tree[pos].val;
    int mid=(l+r)>>1;
    if(x<=mid) ans=max(ans,query(pos<<1,x,y));
    if(mid<y) ans=max(ans,query(pos<<1|1,x,y));
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
}
int main(){
    int n=read(),m=read(),a,b;
    char opt;
    build(1,1,n);
    for(;m--;){
        cin>>opt;
        a=read(),b=read();
        if(opt=='Q') cout<<query(1,a,b)<<endl;
        else update(1,a,b);
    }
}