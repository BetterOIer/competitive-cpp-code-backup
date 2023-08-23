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
    int mid;
    int val;
}tree[100005];
void pushup(int pos){
    tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
}
void build(int pos,int l,int r){
    int mid=(l+r)>>1;
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].mid=mid;
    if(l==r){
        tree[pos].val=read();
        return;
    }
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
int query(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r,mid=tree[pos].mid;
    if(x<=l&&r<=y) return tree[pos].val;
    int ans=2147483647;
    if(mid<y)ans=min(ans,query(pos<<1|1,x,y));
    if(mid>=x) ans=min(ans,query(pos<<1,x,y));
    return ans;
}
int main(){
    int n=read(),m=read(),u;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        n=read(),u=read();
        cout<<query(1,n,u)<<" ";
    }
    return 0;
}