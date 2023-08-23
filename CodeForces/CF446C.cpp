// TODO
#include<iostream>
using namespace std;
const int mod = 1000000009;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
struct node{
    int val;
}tree[1400001];
long long feb[1000001],tag1[1400001],tag2[1400001];
void pushup(int pos){
    tree[pos].val=(tree[pos<<1].val+tree[pos<<1|1].val)%mod;
}
inline long long Fx(long long a1,long long a2,long long x){
	if (x==1) return a1;
    if (x==2) return a2;
	return (a2*feb[x-1]%mod+a1*feb[x-2]%mod)%mod; 
}
inline long long sumF(long long a1,long long a2,long long x){
	if (x==1) return a1;
    if (x==2) return a1+a2;
	return (Fx(a1,a2,x+2)-a2+mod)%mod;
}
inline void pushtag(int pos, int l, int r,long long val1, long long val2){
    tag1[pos]=(tag1[pos]+val1)%mod;tag2[pos]=(tag2[pos]+val2)%mod;
    tree[pos].val=(tree[pos].val+sumF(val1,val2,r-l+1))%mod;
}
inline void pushdown(int pos, int l, int r){
    int mid = (l+r)>>1;
    if (tag1[pos]==0&&tag2[pos]==0) return;
	pushtag(pos<<1,l,mid,tag1[pos],tag2[pos]);
	pushtag(pos<<1|1,mid+1,r,Fx(tag1[pos],tag2[pos],mid-l+2),Fx(tag1[pos],tag2[pos],mid-l+3));	
	tag1[pos]=tag2[pos]=0;
}
inline void update(int pos, int l, int r, int x, int y){
    if(l>y||r<x) return;
    if(x>=l&&y<=r) return pushtag(pos,l,r,feb[l-x+1],feb[l-x+2]);
    pushdown(pos,l,r);
    int mid = (l+r)>>1;
    update(pos<<1,l,mid,x,y);update(pos<<1|1,mid+1,r,x,y);pushup(pos);
}
inline long long query(int pos,int l,int r,int x,int y){
	if (l>y||r<x) return 0;
	if (l>=x&&r<=y) return tree[pos].val;
	pushdown(pos,l,r);
    int mid = (l+r)>>1;
	return (query(pos<<1,l,mid,x,y)+query(pos<<1|1,mid+1,r,x,y))%mod;
}
inline void build(int pos, int l, int r){
    if(l==r){
        tree[pos].val=read();
        return;
    }
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void out(){
    for(int i = 1;i<=n;i++){
        printf("%lld ",query(1,1,n,i,i));
    } 
    cout<<endl;
}
int main(){
    n=read(),m=read();
    feb[1]=1;
	for (int i=2;i<=2+n;i++) feb[i]=(feb[i-1]+feb[i-2])%mod;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        int op=read(),x=read(),y=read();
        if(op==1){
            update(1,1,n,x,y);
        }else{
            printf("%lld\n",query(1,1,n,x,y));
        }
        out();
    }
}
