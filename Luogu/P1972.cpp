#include<iostream>
using namespace std;
int n,m;
struct node{
	int l,r,x;
}seg[40040404];
#define gc getchar
inline int read(){
	int x=0,f=1;char ch=gc();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
	while (isdigit(ch)){x=x*10ll+ch-'0';ch=gc();}
	return x*f;
}
#define mid ((lb+rb)>>1)
inline void pushup(int rt){
	seg[rt].x=seg[seg[rt].l].x+seg[seg[rt].r].x;
}
int cnt,root[1010101];
void update(int &rt,int lb,int rb,int pos,int w){
	seg[++cnt]=seg[rt];
	rt=cnt;
	if (lb==rb) return (void)(seg[rt].x+=w);
	(mid>=pos?update(seg[rt].l,lb,mid,pos,w):update(seg[rt].r,mid+1,rb,pos,w));
	pushup(rt);
}
int query(int rt,int lb,int rb,int l,int r){
	if (lb>r||rb<l||!rt) return 0;
	if (lb>=l&&rb<=r) return seg[rt].x;
	return query(seg[rt].l,lb,mid,l,r)+query(seg[rt].r,mid+1,rb,l,r);
}
int pre[1010101];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int A=read();
		root[i]=root[i-1];
		int id=pre[A];
		if (id) update(root[i],1,1000000,id,-1);
		update(root[i],1,1000000,i,1);
		pre[A]=i;
	}
	scanf("%d",&m);
	while (m--){
		int l=read(),r=read();
		printf("%d\n",query(root[r],1,1000000,l,r));
	}
	return 0;
}