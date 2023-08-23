#include<iostream>
#include<cmath>
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
    double val;
    double lazy;
    double valC;
    int lazyC;
}tree[120];
void pushup(int pos){
    tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
    tree[pos].valC=tree[pos<<1].valC+tree[pos<<1|1].valC;
}
void pushdown(int pos){
    if(tree[pos].lazy){
        tree[pos<<1].val=tree[pos].lazy*(tree[pos<<1].r-tree[pos<<1].l+1);
        tree[pos<<1|1].val=tree[pos].lazy*(tree[pos<<1|1].r-tree[pos<<1|1].l+1);
        tree[pos<<1].lazy=tree[pos].lazy;
        tree[pos<<1|1].lazy=tree[pos].lazy;
        tree[pos<<1].valC=cos(tree[pos].lazy)*(tree[pos<<1].r-tree[pos<<1].l+1);
        tree[pos<<1|1].valC=cos(tree[pos].lazy)*(tree[pos<<1|1].r-tree[pos<<1|1].l+1);
        tree[pos].lazy=0;
    }
    while(tree[pos].lazyC){
        tree[pos<<1].val=tree[pos<<1].valC;
        tree[pos<<1|1].val=tree[pos<<1|1].valC;
        tree[pos<<1].valC=(tree[pos<<1].r-tree[pos<<1].l+1)*cos(tree[pos<<1].valC/(tree[pos<<1].r-tree[pos<<1].l+1));
        tree[pos<<1|1].valC=(tree[pos<<1|1].r-tree[pos<<1|1].l+1)*cos(tree[pos<<1|1].valC/(tree[pos<<1|1].r-tree[pos<<1|1].l+1));
        tree[pos<<1].lazyC--;
        tree[pos<<1|1].lazyC--;
    }
    return;
}
void updataD(int pos,int x,int y,double data){
    int l = tree[pos].l,r=tree[pos].r;
    int len=r-l+1,mid=(l+r)>>1;
    if(l>=x&&r<=y){
        tree[pos].val=len*data;
        tree[pos].lazy=data;
        tree[pos].lazyC=0;
        tree[pos].valC=len*cos(data);
        return;
    }
    pushdown(pos);
    if(mid>=x) updataD(pos<<1,x,y,data);
    if(mid<y) updataD(pos<<1|1,x,y,data);
    pushup(pos);
}
void updataC(int pos,int x,int y){
    int l = tree[pos].l,r=tree[pos].r;
    int len=r-l+1,mid=(l+r)>>1;
    if(l>=x&&r<=y){
        tree[pos].val=tree[pos].valC;
        tree[pos].lazyC++;
        return;
    }
    pushdown(pos);
    if(mid>=x) updataC(pos<<1,x,y);
    if(mid<y) updataC(pos<<1|1,x,y);
    pushup(pos);
}
double query(int pos, int x,int y){
    int l = tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y) return tree[pos].val;
    pushdown(pos);
    int mid=(l+r)>>1;
    double ans=0;
    if(mid>=x) ans=(ans+query(pos<<1,x,y));
    if(mid<y) ans=(ans+query(pos<<1|1,x,y));
    return ans;
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        cin>>tree[pos].val;
        tree[pos].valC=cos(tree[pos].val);
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
    return;
}
int main(){
    //freopen("seque.in","r",stdin);
    //freopen("seque.out","w",stdout);
    int n,m,opt,x,y,k;
    cin>>n>>m;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        cin>>opt;
        if(opt==3){
            cin>>x>>y>>k;
            updataD(1,x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}