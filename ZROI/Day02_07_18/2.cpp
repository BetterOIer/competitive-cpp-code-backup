/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
const int mod = 1000000009;
inline long long read(){
    register long long x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}
#define mid ((lb+rb)>>1)
long long n,m,f[1000001],a[340201],seg[1400001],tag1[1400001],tag2[1400001];
inline void pushup(int rt){
	seg[rt]=(seg[rt<<1]+seg[rt<<1|1])%mod;
}
inline long long Fx(long long a1,long long a2,long long x){
	if (x==1) return a1;
    if (x==2) return a2;
	return (a2*f[x-1]%mod+a1*f[x-2]%mod)%mod; 
}
inline long long sumF(long long a1,long long a2,long long x){
	if (x==1) return a1;
    if (x==2) return a1+a2;
	return (Fx(a1,a2,x+2)-a2+mod)%mod;
}
void build(int rt,int lb,int rb){
	if (lb==rb) return (void)(seg[rt]=a[lb]);
	build(rt<<1,lb,mid);build(rt<<1|1,mid+1,rb);pushup(rt);
}
inline void pushtag(int rt,int lb,int rb,long long a1,long long a2){
	tag1[rt]=(tag1[rt]+a1)%mod;tag2[rt]=(tag2[rt]+a2)%mod;
	seg[rt]=(seg[rt]+sumF(a1,a2,rb-lb+1))%mod;
}
inline void pushdown(int rt,int lb,int rb){
	if (tag1[rt]==0&&tag2[rt]==0) return;
	pushtag(rt<<1,lb,mid,tag1[rt],tag2[rt]);
	pushtag(rt<<1|1,mid+1,rb,Fx(tag1[rt],tag2[rt],mid-lb+2),Fx(tag1[rt],tag2[rt],mid-lb+3));	
	tag1[rt]=tag2[rt]=0;
}
long long query(int rt,int lb,int rb,int l,int r){
	if (lb>r||rb<l) return 0;
	if (lb>=l&&rb<=r) return seg[rt];
	pushdown(rt,lb,rb);
	return (query(rt<<1,lb,mid,l,r)+query(rt<<1|1,mid+1,rb,l,r))%mod;
}
void update(int rt,int lb,int rb,int l,int r){
	if (lb>r||rb<l) return;
	if (lb>=l&&rb<=r) return (void)(pushtag(rt,lb,rb,f[lb-l+1],f[lb-l+2]));
	pushdown(rt,lb,rb);
	update(rt<<1,lb,mid,l,r);update(rt<<1|1,mid+1,rb,l,r);pushup(rt);
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	f[1]=1;
	for (int i=2;i<=2+n;i++) f[i]=(f[i-1]+f[i-2])%mod;
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