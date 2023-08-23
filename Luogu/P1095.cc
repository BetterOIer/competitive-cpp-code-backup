#include<bits/stdc++.h>
#define reg register
using namespace std;

const int N = 1e6 + 10;
const int M = 2e6 + 10;

int head[N], ver[M], Next[M], e[M], p[M];

void add(reg int x, reg int y, reg int edge, reg int pi) {
	static int cnt = 0;
	ver[++cnt] = y, Next[cnt] = head[x], head[x] = cnt;
	e[cnt] = edge, p[cnt] = pi;
	
	ver[++cnt] = x, Next[cnt] = head[y], head[y] = cnt;
	e[cnt] = edge, p[cnt] = pi;
}

bool vis[N]; int End, Ep, Ee;
vector<int> ring;
long long ans[N];

bool dfs(reg int x, reg int fa, reg int fp, reg int fe) {
	if(vis[x]) { 
		End = x, Ep = fp, Ee = fe;
		return true;
	}
	vis[x] = 1;
	for(reg int i = head[x]; i; i = Next[i]) {
		reg int y = ver[i];
		if(y == fa) continue;
		if(dfs(y, x, p[i], e[i])) {
			if(x != End) 
				ans[x] -= fp > p[i] ? e[i] : fe;
			else  ans[x] -= p[i] > Ep ? Ee : e[i];
                        // 减去不会经过的边的答案
			ring.push_back(x);
			return x != End;
		}
	}
	return false;
}

void dfs(reg int x) { // 给子树赋值
	vis[x] = 1;
	for(reg int i = head[x]; i; i = Next[i]) {
		reg int y = ver[i];
		if(vis[y]) continue;
		ans[y] = ans[x];
		dfs(y);
	}
}

int read() {
	static char c;
	static int x;
	while(!isdigit(c = getchar()));
	x = c ^ 48;
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + (c ^ 48);
	return x;
}

int main() {
	reg int n = read();
	reg long long sum = 0;
	for(reg int i = 1, x, y, e, p; i <= n; i++) {
		x = read(), y = read();
		e = read(), p = read();
		add(x, y, e, p);
		sum += e; // 把所有边权叠加
	}
	dfs(1, 0, 0, 0);
    int size=sizeof vis;
    for(int i = 0;i<size;i++) cout<<(int)vis[i]<<" ";
    memset(vis, 0, sizeof vis);
	for(reg int i = 0; i < (int)ring.size(); i++) 
		vis[ring[i]] = 1, ans[ring[i]] += sum;
       // 计算环上的答案
	for(reg int i = 0; i < (int)ring.size(); i++) 
		dfs(ring[i]);
	for(reg int i = 1; i <= n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
