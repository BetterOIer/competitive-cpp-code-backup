#include<iostream>
#include<algorithm>
#define maxn 200001
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void out(int a){
	if(a>=10) out(a/10);
	putchar(a%10)+'0';
}
struct node{
	int l,r,val;
}tree[maxn*20];
int n,m;
int cnt,root[maxn],b[maxn],a[maxn],len;
inline void build(int &root,int l,int r){
	root=++cnt;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(tree[root].l,l,mid);build(tree[root].r,mid+1,r);
}
inline void ch(int &root,int now,int l,int r,int pos){
	root=++cnt;
	tree[root]=tree[now];
	tree[root].val++;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(mid>=pos) ch(tree[root].l,tree[now].l,l,mid,pos);
	else ch(tree[root].r,tree[now].r,mid+1,r,pos);
}
inline int query(int lp,int rp,int l,int r,int pos){
	int x=tree[tree[rp].l].val-tree[tree[lp].l].val;
	if(l==r) return b[l];
	int mid=(l+r)>>1;
	if(x>=pos) return query(tree[lp].l,tree[rp].l,l,mid,pos);
	return query(tree[lp].r,tree[rp].r,mid+1,r,pos-x);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=b[i]=read();
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	build(root[0],1,len);
	for(int i=1;i<=n;++i){
		int now=lower_bound(b+1,b+len+1,a[i])-b;
		ch(root[i],root[i-1],1,len,now);
	}
	while(m--){
		int l=read(),r=read(),k=read();
		printf("%d\n",query(root[l-1],root[r],1,len,k));
	}
	return 0;
}