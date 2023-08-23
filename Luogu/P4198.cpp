#include<bits/stdc++.h>
using namespace std;
struct node {
	int l,r,v;
	double mx;
	node(){mx=0,v=0;}
}t[400001];
int  read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
void build(int pos,int l,int r) {
	t[pos].l=l;
	t[pos].r=r;
	if(l!=r) {
		int mid=(l+r)>>1;
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
	}
}
void pushup(int pos) {
	t[pos].mx=max(t[pos<<1].mx,t[pos<<1|1].mx);
}
int pushdown(int pos,double h) {
	if(t[pos].l==t[pos].r)return t[pos].mx>h;
	if(t[pos<<1].mx<h)return pushdown(pos<<1|1,h);
	return pushdown(pos<<1,h)+t[pos].v-t[pos<<1].v;
}
void update(int pos,int x,double v) {
	if(t[pos].l==t[pos].r) {
		t[pos].mx=v;
		t[pos].v=1;
		return;
	}
	int mid=(t[pos].l+t[pos].r)>>1;
	if(x<=mid)update(pos<<1,x,v);
	else update(pos<<1|1,x,v);
	pushup(pos);
	t[pos].v=t[pos<<1].v+pushdown(pos<<1|1,t[pos<<1].mx);
}
int main() {
	int n=read(),m=read();
	build(1,1,n);
	while(m--) {
		int x=read(),y=read();
		update(1,x,y*1.0/x);
		cout<<t[1].v<<endl;
	}
	return 0;
}
