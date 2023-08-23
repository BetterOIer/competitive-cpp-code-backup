#include<iostream>
#include<cstring>
#define MAXN 100010
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long T,N,Q;
long long A;
struct Tnode{
    long long l;
    long long r;
    long long val;
    long long lazy;
}tree[(MAXN<<2)];
struct node{
    long long l,r,opt;
    long long p ;
}cmd[MAXN];
void pushup(long long pos){
    tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
}
void build(long long pos,long long l,long long r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        tree[pos].val= read();
        return;
    }
    long long mid=(l+r)>>1 ;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void pushdown(long long pos){
    if( tree[pos].lazy == 0 ) return ;
    tree[pos<<1].lazy+=tree[pos].lazy;
    tree[pos<<1].val+=tree[pos].lazy;
    tree[pos<<1|1].lazy+=tree[pos].lazy;
    tree[pos<<1|1].val+=tree[pos].lazy;
    tree[pos].lazy=0;
}
void update(long long pos, long long L, long long R, long long data){
    long long l=tree[pos].l,r=tree[pos].r,mid=(l+r)>>1;
    if(l>=L&&r<=R){
        tree[pos].lazy+=data;
        tree[pos].val+=data;
        return;
    }
    pushdown(pos);
	if(mid>=L)update(pos<<1,L,R,data);
	if(mid<R)update(pos<<1|1,L,R,data);
	pushup(pos);
}
long long query(long long pos, long long L, long long R){
    long long l=tree[pos].l,r=tree[pos].r,mid=(l+r)>>1;
    if(l>=L&&r<=R)return tree[pos].val;
    pushdown(pos);
    long long ans=1e18;
	if(mid>=L)ans=min(ans,query(pos<<1,L,R));
	if(mid<R)ans=min(ans,query(pos<<1|1,L,R));
	pushup(pos);
	return ans;
}
int main(){
    T = read();
    while(T--){
        memset(tree,0,sizeof tree);
        memset(cmd,0,sizeof cmd);
        N=read(),Q=read();
        for(long long i = 1;i<=N;i++)A=read();
        for(long long i = 1;i<=Q;i++){
            cmd[i].opt = read();
            cmd[i].l = read();
            cmd[i].r = read();
            if(cmd[i].opt==1) cmd[i].p=read();
        }
        build(1,1,N);
        for(long long i = Q;i >= 1;i--){
            if(cmd[i].opt == 1 ) update(1,cmd[i].l,cmd[i].r,0-cmd[i].p);
            else cmd[i].p=query(1,cmd[i].l,cmd[i].r);
        }
        for(long long i = 1;i<= Q; i++) if(cmd[i].opt==2) cout<<cmd[i].p<<" ";
    }
    return 0;
}