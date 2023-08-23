求广义斐波那契前$n$项的值

$$\sum_{i=1}^n F(n) = F(n+2)-F(2)$$

```cpp
#include<bits/stdc++.h>
#define ll long long
#define ljc 1000000009
using namespace std;
/*
线段树+广义斐波那契数列。
每一个节点维护两个标记，a1,a2,这个区间表示增加的广义斐波那契数列的
第一项，第二项。 
*/
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
#endif
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
#define mid ((lb+rb)>>1)
ll n,m,f[1000001],a[340201],seg[1400001],tag1[1400001],tag2[1400001];
inline void pushup(int rt){
	seg[rt]=(seg[rt<<1]+seg[rt<<1|1])%ljc;
}
inline ll Fx(ll a1,ll a2,ll x){
	if (x==1) return a1;if (x==2) return a2;
	return (a2*f[x-1]%ljc+a1*f[x-2]%ljc)%ljc; 
}
inline ll sumF(ll a1,ll a2,ll x){
	if (x==1) return a1;if (x==2) return a1+a2;
	return (Fx(a1,a2,x+2)-a2+ljc)%ljc;
}
void build(int rt,int lb,int rb){
	if (lb==rb) return (void)(seg[rt]=a[lb]);
	build(rt<<1,lb,mid);build(rt<<1|1,mid+1,rb);pushup(rt);
}
inline void pushtag(int rt,int lb,int rb,ll a1,ll a2){
	tag1[rt]=(tag1[rt]+a1)%ljc;tag2[rt]=(tag2[rt]+a2)%ljc;
	seg[rt]=(seg[rt]+sumF(a1,a2,rb-lb+1))%ljc;
}
inline void pushdown(int rt,int lb,int rb){
	if (tag1[rt]==0&&tag2[rt]==0) return;
	pushtag(rt<<1,lb,mid,tag1[rt],tag2[rt]);
	pushtag(rt<<1|1,mid+1,rb,Fx(tag1[rt],tag2[rt],mid-lb+2),Fx(tag1[rt],tag2[rt],mid-lb+3));	
	tag1[rt]=tag2[rt]=0;
}
ll query(int rt,int lb,int rb,int l,int r){
	if (lb>r||rb<l) return 0;
	if (lb>=l&&rb<=r) return seg[rt];
	pushdown(rt,lb,rb);
	return (query(rt<<1,lb,mid,l,r)+query(rt<<1|1,mid+1,rb,l,r))%ljc;
}
void update(int rt,int lb,int rb,int l,int r){
	if (lb>r||rb<l) return;
	if (lb>=l&&rb<=r) return (void)(pushtag(rt,lb,rb,f[lb-l+1],f[lb-l+2]));
	pushdown(rt,lb,rb);
	update(rt<<1,lb,mid,l,r);update(rt<<1|1,mid+1,rb,l,r);pushup(rt);
}
signed main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	f[1]=1;
	for (int i=2;i<=2+n;i++) f[i]=(f[i-1]+f[i-2])%ljc;
	build(1,1,n);
	for (int i=1;i<=m;i++){
		int op=read(),x=read(),y=read();
		if (op==1){
			update(1,1,n,x,y);
		}else{
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
    return 0;
}
```