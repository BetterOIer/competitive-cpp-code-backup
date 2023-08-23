#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;++i)
#define pr(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1e5+9;
int ans,n,fa[N],h[N],ch[N];
vector<int> T[N];
struct rvec{
	vector<int> z;
	int& operator[](int i){
		return z[z.size()-1-i];
	}
	void push_front(int x){
		z.pb(x);
	}
	void pop_front(){
		if(!z.empty()){
			z.pop_back();
		}
	}
	void swap(rvec &x){
		z.swap(x.z);
	}
}f[N];
struct lvec{
	vector<ll> z;
	int l;
	lvec(){
		l=-1;
	}
	void shift(){
		++l;
		z.push_back(0);
		if(l){
			z.push_back(0);
		}
	}
	ll& operator[](int i){
		return z[l+i];
	}
	void swap(lvec &x){
		std::swap(l,x.l);
		z.swap(x.z);
	}
}g[N];
void dfs0(int u){
	for(int v:T[u]){
		if(v!=fa[u]){
			fa[v]=u;
			dfs0(v);
			if(h[v]>=h[u]){
				h[u]=h[v]+1;
				ch[u]=v;
			}
		}
	}
}
void dfs1(int u){
	if(ch[u]){
		dfs1(ch[u]);
	}
	f[u].swap(f[ch[u]]);
	f[u].push_front(1);
	g[u].swap(g[ch[u]]);
	g[u].shift();
	ans+=g[u][0];
	for(int v:T[u]){
		if(v!=fa[u]&&v!=ch[u]){
			dfs1(v);
			rp(i,0,h[v]){
				ans+=f[v][i]*g[u][i+1];
				if(i){
					ans+=g[v][i]*f[u][i-1];
				}
			}
			rp(i,0,h[v]){
				g[u][i+1]+=1ll*f[u][i+1]*f[v][i];
				if(i){
					g[u][i-1]+=g[v][i];
				}
				f[u][i+1]+=f[v][i];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	rp(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		T[u].pb(v);
		T[v].pb(u);
	}
	dfs0(1);
	dfs1(1);
	printf("%lld\n",ans);
	return 0;
}
/* 
void insert(int x){
	if(x == st[1]) return;
	int y = lca(x, st[top]);
	if(y != st[top]) {
		while(top >1&&dfn_t[y] <dfn_t[st[top -1]]) {ans += sz[st[top]] - sz[st[top -1]], top--;}
		if(dfn_t[y] >dfn_t[st[top -]]) {ans += sz[st[top]] - sz[y];st[top] = y;}
		else{ans += sz[st[top--]] - sz[y];}
	}
	st[++top] =x;
} */