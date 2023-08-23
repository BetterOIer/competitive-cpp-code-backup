#include <bits/stdc++.h>
using namespace std;

const int maxn=400000;
int n;
vector<int> g[maxn+50];
int sz[maxn+50];
int f[maxn+50],f2[maxn+50],h[maxn+50];
bool ans[maxn+50];

void dfs(int u,int fa){
	sz[u]=1;
	f[u]=f2[u]=0;
	for (auto v:g[u]) if (v!=fa){
		dfs(v,u);
		if (sz[v]-f[v]>n/2) ans[u]=0;
		sz[u]+=sz[v];
		int upd=(sz[v]<=n/2)?(sz[v]):(f[v]);
		if (upd>=f[u]) f2[u]=f[u],f[u]=upd;
		else if (upd>=f2[u]) f2[u]=upd;
	}
}
void dfs2(int u,int fa){
	for (auto v:g[u]) if (v!=fa){
		if (n-sz[v]<=n/2) h[v]=n-sz[v];
		else{
			h[v]=h[u];
			int p=(sz[v]<=n/2)?(sz[v]):(f[v]);
			if (p==f[u]) h[v]=max(h[v],f2[u]);
			else h[v]=max(h[v],f[u]);
		}
		dfs2(v,u);
	}
	if (n-sz[u]-h[u]>n/2) ans[u]=0;
}

int main(){
//	freopen("reform.in","r",stdin);
//	freopen("reform.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (;T--;){
		cin >> n;
		for (int i=1;i<n;i++){
			int x,y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for (int i=1;i<=n;i++) ans[i]=1;
		dfs(1,0);
		dfs2(1,0);
		for (int i=1;i<=n;i++) cout << ans[i] << ' ';
		cout << '\n';
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++) ans[i]=0;
	}
	return 0;
}
