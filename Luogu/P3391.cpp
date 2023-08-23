#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn=100005;
const int mod=998244353;
struct node{
	int l,r,size,val;
	bool f1;
}a[maxn];
int tot=0;
int New(int val){
	a[++tot].size=1;
	a[tot].val=val;
	return tot;
}
void push_down(int p){
	swap(a[p].l,a[p].r);
	if(a[p].l)a[a[p].l].f1^=1;
	if(a[p].r )a[a[p].r].f1^=1;
	a[p].f1=0;
}
void updata(int p){
    a[p].size=a[a[p].l].size+a[a[p].r].size+1;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(mod%(a[x].size+a[y].size)<a[x].size ){
		if(a[x].f1)push_down(x);
		a[x].r=merge(a[x].r,y);
		updata(x);return x;
	}
	else{
		if(a[y].f1)push_down(y);
		a[y].l=merge(x,a[y].l);
		updata(y);return y;
	}
}
void split(int p,int k,int &x,int &y){
	if(!p){
		x=y=0;
		return;
	}
	if(a[p].f1)push_down(p);
	if(a[a[p].l].size<k)x=p,split(a[p].r,k-a[a[p].l].size-1,a[p].r,y);
	else y=p,split(a[p].l,k,x,a[p].l);
	updata(p);
}
void print(int p){
	if(!p)return;
	if(a[p].f1)push_down(p);
	print(a[p].l);
	cout<<a[p].val<<" ";
	print(a[p].r); 
}
int build(int l,int r){
	if(l==r)return New(l);
	int mid=(l+r)>>1;
	return merge(build(l,mid),build(mid+1,r));
}
int n,m,root;
int main(){
    n=read(),m=read();
	root=merge(root,build(1,n));
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		int x,y,z;
		split(root,l-1,x,y);
		split(y,r-l+1,y,z);
		a[y].f1^=1;
		root=merge(merge(x,y),z);
	}
	print(root);
}