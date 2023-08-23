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
    int lazy=-1;
    int val;
}tree[15000001];
int n,m,cnt,root;
void pushdown(int pos,int ll,int rr){
    if(~tree[pos].lazy){
        int mid = (ll+rr)>>1,l = tree[pos].l,r= tree[pos].r;
        if(!l)tree[pos].l=l=++cnt;
        if(!r)tree[pos].r=r=++cnt;
        tree[l].lazy=tree[r].lazy=tree[pos].lazy;
        tree[l].val=(mid-ll+1)*tree[pos].lazy;
        tree[r].val=(rr-mid)*tree[pos].lazy;
        tree[pos].lazy=-1;
    }
}
void pushup(int pos){
    tree[pos].val=tree[tree[pos].l].val+tree[tree[pos].r].val;
}
void update(int &pos,int x,int y,int l,int r,int data){
    if(l>y||x>r) return;
    if(!pos)pos=++cnt;
    if(l>=x&&r<=y){
        tree[pos].val = data*(r-l+1);
        tree[pos].lazy = data;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(pos,l,r);
    update(tree[pos].l,x,y,l,mid,data);
    update(tree[pos].r,x,y,mid+1,r,data);
    pushup(pos);
}
int main(){
    int n=read(),q=read();
    for(int i = 1,x,y,z;i<=q;i++){
        x=read(),y=read(),z=read();
        if(z==1){
            update(root,x,y,1,n,1);
        }else{
            update(root,x,y,1,n,0);
        }
        printf("%d\n",n-tree[1].val);
    }
}