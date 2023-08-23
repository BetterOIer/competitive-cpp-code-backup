#include<iostream>
using namespace std;
const long long N=1e6+7;
struct edge{
	long long nxt,v,w;
}e[N<<1];
long long h[N],cnt;
inline void add_edge(long long u,long long v,long long w){
	e[++cnt].nxt=h[u],e[cnt].v=v,e[cnt].w=w;
	h[u]=cnt;
}
long long n,q;
long long x,y,l,r;
long long dis[N];
inline long long read(){
	long long sum=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') sum=(sum<<3)+(sum<<1)+(ch^48),ch=getchar();
	return sum;
}
inline void dfs(long long u,long long fa){
	for(long long i=h[u];i;i=e[i].nxt){
		long long v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dis[v]=dis[u]^w;
		dfs(v,u);
	}
}
inline void write(long long x){
	if(x/10) write(x/10);
	putchar(x%10^48);
}
signed main(){
	//freopen("10.in","r",stdin);
	//freopen("10.out","w",stdout);
	n=read(),q=read();
	for(long long i=1;i<n;i++){
		long long u=read(),v=read(),w=read();
		add_edge(u,v,w),add_edge(v,u,w);
	}
	dfs(1,0);
	for(long long i=1;i<=q;i++){
		x=read(),y=read(),l=read(),r=read();
		write(r-l+1&1?dis[x]^dis[y]:0),putchar('\n');
	}
	return 0;
}
