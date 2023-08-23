#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,maxn=0;
int a[200005];
struct ASK{
    int l;
    int r;
    int id;
    int ans;
}ask[200005];
struct node{
    int val;
}tree[200005<<2];
bool cmp(ASK a,ASK b){
    return a.r<b.r;
}
bool cmp1(ASK a,ASK b){
    return a.id<b.id;
}
void pushup(int pos){
    tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
}
void update(int pos, int l,int r,int val,int x){
    if(l==r){
        tree[pos].val=max(tree[pos].val,x);
        return;
    }
    int mid = (l+r)>>1;
    if(val<=mid) update(pos<<1,l,mid,val,x);
    else update(pos<<1|1,mid+1,r,val,x);
    pushup(pos);
}
int query(int pos,int l,int r,int val){
    if(l==r){
        return l;
    }
    int mid = (l+r)>>1;
    if(tree[pos<<1].val<val) return query(pos<<1,l,mid,val);
    else return query(pos<<1|1,mid+1,r,val);
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        maxn = max(maxn,a[i]);
    }
    for(int i = 1;i<=m;i++){
        ask[i].l=read();
        ask[i].r=read();
        ask[i].id=i;
    }
    ++maxn;
    sort(ask+1,ask+m+1,cmp);
    int now = 1;
    for(int i = 1;i<=n;i++){
        update(1,0,maxn,a[i],i);
        while(i>=ask[now].r&&now<=n){
            ask[now].ans=query(1,0,maxn,ask[now].l);
            now++;
        }
    }
    sort(ask+1,ask+m+1,cmp1);
    for(int i = 1;i<=n;i++){
        printf("%d\n",ask[i].ans);
    }
}