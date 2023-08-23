// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second 
using namespace std;
const int MAXN = 3e5 + 10;
const long long INF = 1e15 + 10;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct EDGE {
    int u, v, w;
    bool operator < (const EDGE &rhs) const {
    	return w < rhs.w;
    }
}E[MAXN];
vector<pair<int, int> > v[MAXN];
int N, M, fa[MAXN], vis[MAXN], dep[MAXN], f[MAXN][19], mx[MAXN][19], me[MAXN][19];;
long long sum;
int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void Kruskal() {
    sort(E + 1, E + M + 1);
    int tot = 0;
    for (int i = 1; i <= M; i++) {
        int x = E[i].u, y = E[i].v, fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy; 
            tot++, sum += E[i].w, vis[i] = 1;
            v[x].push_back(MP(y, E[i].w)); 
            v[y].push_back(MP(x, E[i].w));
        }
        if (tot == N - 1) break;
    }
}
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1; f[x][0] = fa; 
    for(int i = 0, to; i < v[x].size(); i++) {
    	if((to = v[x][i].fi) == fa) continue;
    	mx[to][0] = v[x][i].se;
    	dfs(to, x);
    }
}
int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 18; i >= 0; i--) if (dep[ f[x][i] ] >= dep[y] ) x = f[x][i];
    if (x == y) return x;
    for (int i = 18; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int findmax(int x, int lca, int val) {
    long long ans = 0;
    for (int i = 18; i >= 0; i--) {
        if (dep[ f[x][i] ] >= dep[lca]) {
            if (mx[x][i] == val) ans = max(ans, (long long) me[x][i]);
            else ans = max(ans, (long long) mx[x][i]);
            x = f[x][i];
        }
    }
    return ans;
}
int main() {
    N = read(), M = read();
    for (int i = 1; i <= N; i++) fa[i] = i;
    for (int i = 1; i <= M; i++) {
        int x = read(), y = read(), z = read();
        E[i] = (EDGE) {x, y, z};
    }
    Kruskal();
    dfs(1, 0);
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= N; j++) {
            f[j][i] = f[ f[j][i - 1] ][i - 1];
            int topf = f[j][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[topf][i - 1]);
            me[j][i] = max(me[j][i - 1], me[topf][i - 1]);
            if (mx[j][i - 1] > mx[topf][i - 1]) me[j][i] = max(me[j][i], mx[topf][i - 1]);
            else if (mx[j][i - 1] < mx[topf][i - 1]) me[j][i] = max(me[j][i], mx[j][i - 1]);
        }
    }
    long long ans = INF;
    for (int i = 1; i <= M; i++) {
        if (vis[i]) continue;
        int x = E[i].u, y = E[i].v, z = E[i].w;
        int lca = LCA(x, y);
        int lmx = findmax(x, lca, z), rmx = findmax(y, lca, z);
        if (max(lmx, rmx) != z)  ans = min(ans, sum + z - max(lmx, rmx));
    }
    printf("%lld", ans);
    return 0;
}