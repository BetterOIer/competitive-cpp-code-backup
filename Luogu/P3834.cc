//TODO rewrite
#include<iostream>
#include<algorithm> 
using namespace std;
#define maxn 200001
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,len,root,cnt;
int a[maxn],b[maxn];
struct node{
	int l,r,val;
}tree[maxn*20];
void build(int pos,int l,int r){
    root=++cnt;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(tree[root].l,l,mid);build(tree[root].r,mid+1,r);
}
int main(){
    n=read(),m=read();
    for(int i= 1;i<=n;i++){
        b[i]=a[i]=read();
    }
    sort(b+1,b+n+1);
    len=unique(b+1,b+n+1)-b-1;
}