#include<iostream>
using namespace std;
const int mod = 571373;
int a[100005];
struct node{
    int l;
    int r;
    int val;
    int lazy;
    int mu=1;
}tree[600005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}

void pushup(int pos){
    tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
}
void pushdown (int pos){
    if(tree[pos].lazy||tree[pos].mu!=1){
        tree[pos<<1].mu=(tree[pos<<1].mu*tree[pos].mu)%mod;
        tree[pos<<1|1].mu=(tree[pos<<1|1].mu*tree[pos].mu)%mod;
        tree[pos<<1].lazy=(tree[pos<<1].lazy*tree[pos].mu)%mod;
        tree[pos<<1|1].lazy= (tree[pos<<1|1].lazy*tree[pos].mu)%mod;
        tree[pos<<1].val=(tree[pos<<1].val*tree[pos].mu)%mod;
        tree[pos<<1|1].val=(tree[pos<<1|1].val*tree[pos].mu)%mod;
        tree[pos].mu=1;
        tree[pos<<1].val=(tree[pos<<1].val+tree[pos].lazy*(tree[pos<<1].r-tree[pos<<1].l+1))%mod;
        tree[pos<<1|1].val=(tree[pos<<1|1].val+tree[pos].lazy*(tree[pos<<1|1].r-tree[pos<<1|1].l+1))%mod;
        tree[pos<<1].lazy=(tree[pos].lazy+tree[pos<<1].lazy)%mod;
        tree[pos<<1|1].lazy=(tree[pos].lazy+tree[pos<<1|1].lazy)%mod;
        tree[pos].lazy=0;
    }
}
void updatepoint(int pos,int x,int data){
    if(tree[pos].l==x&&tree[pos].r==x) tree[pos].val+=data;
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid<x) updatepoint(pos<<1|1,x,data);
    else updatepoint(pos<<1,x,data);
    pushup(pos);
}
void updatearea(int pos,int l,int r,int data){
    if(tree[pos].l>=l&&tree[pos].r<=r){
        tree[pos].val+=((tree[pos].r-tree[pos].l+1)*data);
    }
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid>=l) updatearea(pos<<1,l,r,data);
    else updatearea(pos<<1|1,l,r,data);
    pushup(pos);
}

int querypoint(int pos,int x){
    if(tree[pos].l==x&&tree[pos].r==x) return tree[pos].val;
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid<x) return querypoint(pos<<1|1,x);
    else return querypoint(pos<<1,x);
}
long long queryarea_add(int x,int y,int pos){
    if(x<=tree[pos].l&&y>=tree[pos].r) return tree[pos].val;
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=-10000000;
    if(mid>=x)ans+=queryarea_add(x,y,pos<<1);
    if(mid<y)ans+=queryarea_add(x,y,pos<<1|1);
    return ans;
}

void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r) {tree[pos].val=read();return;}
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}

int main(){
    int n,m,p;
    build(1,1,n);
}