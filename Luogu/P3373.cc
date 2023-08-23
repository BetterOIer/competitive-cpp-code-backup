#include<iostream>
using namespace std;
int mod;
int a[100005];
struct node{
    int l;
    int r;
    long long val;
    long long lazy;
    long long mu=1;
}tree[400005];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void pushup(int pos){
    tree[pos].val=(tree[pos<<1].val+tree[pos<<1|1].val)%mod;
}
void pushdown(int pos){
    if(tree[pos].lazy||tree[pos].mu!=1){
        tree[pos<<1].mu=(tree[pos<<1].mu*tree[pos].mu)%mod;
		tree[pos<<1|1].mu=(tree[pos<<1|1].mu*tree[pos].mu)%mod;
		tree[pos<<1].lazy=(tree[pos<<1].lazy*tree[pos].mu)%mod;
		tree[pos<<1|1].lazy=(tree[pos<<1|1].lazy*tree[pos].mu)%mod;
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
void updatarea_add(int pos,int x,int y,int data){
    int l = tree[pos].l,r=tree[pos].r;
    int len=r-l+1,mid=(l+r)>>1;
    if(l>=x&&r<=y){
        tree[pos].val+=len*data;
        tree[pos].lazy+=data;
        return;
    }
    pushdown(pos);
    if(mid>=x) updatarea_add(pos<<1,x,y,data);
    if(mid<y) updatarea_add(pos<<1|1,x,y,data);
    pushup(pos);
}
void updatearea_acu(int pos,int x,int y,int data){
    int l = tree[pos].l,r=tree[pos].r;
    int mid=(l+r)>>1;
    if(l>=x&&r<=y){
        tree[pos].val=(tree[pos].val*data)%mod;
        tree[pos].lazy=(tree[pos].lazy*data)%mod;
        tree[pos].mu=(tree[pos].mu*data)%mod;
        return;
    }
    pushdown(pos);
    if(mid>=x) updatearea_acu(pos<<1,x,y,data);
    if(mid<y) updatearea_acu(pos<<1|1,x,y,data);
    pushup(pos);
}
long long query(int x,int y,int pos){
    int l = tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y) return tree[pos].val;
    pushdown(pos);
    int mid=(l+r)>>1;
    long long ans=0;
    if(mid>=x) ans=(ans+query(x,y,pos<<1))%mod;
    if(mid<y) ans=(ans+query(x,y,pos<<1|1))%mod;
    return ans;
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r) {tree[pos].val=read()%mod;return;}
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
int main(){
    int n,m,opt,x,y,k;
    cin>>n>>m>>mod;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        cin>>opt;
        if(opt==1){
            cin>>x>>y>>k;
            updatearea_acu(1,x,y,k);
        }else if(opt==2){
            cin>>x>>y>>k;
            updatarea_add(1,x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(x,y,1)<<endl;
        }
    }
}