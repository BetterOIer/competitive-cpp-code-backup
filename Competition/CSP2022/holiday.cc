#include<iostream>
#include<vector>
using namespace std;
int k;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>G[2505];
int val[2505];
int main(){
    int n=read(),m=read();
    k=read();
    for(int i = 2;i<=n;i++){
        val[i]=read();
    }
    for(int i =1,u,v;i<=m;i++){
        u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u)
        bfs(u);

    int ans = 0;
    
    for (int b = 2; b <= n; ++b)
        for (int c = 2; c <= n; ++c) if (ok[b][c])
            for (int a : f[b])
                for (int d : f[c])
                    if (a != c && b != d && a != d)
                    gmx(ans, w[a] + w[b] + w[c] + w[d]);

    printf("%lld\n", ans);
    return 0;
}