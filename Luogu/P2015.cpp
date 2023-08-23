#include<iostream>
#include<vector>
using namespace std;
const int maxn = 105;
const int inf = 1 << 29;
int f[maxn][maxn], n, Q,u,v,w;
struct edge{
    int v;
    int w;
};
vector<edge> edges[maxn];
void dfs(int u, int fa){
    for (int k = 1; k <= Q; k++) f[u][k] = -inf,
    f[u][0] = 0;
    for (auto e: edges[u])
    if (e.v != fa){
        dfs(e.v, u);
        for (int k = Q; k >= 1; k--)
        for (int j= 0; j < k; j++)
            f[u][k] = max(f[u] [k], f[u][j] + f[e.v][k - j - 1] + e.w);
    }
}
int main(){
    cin>>n>>Q;
    for(int i = 1;i<=n-1;i++){
        cin>>u>>v>>w;
        edges[u].push_back((edge){v,w});
        edges[v].push_back((edge){u,w});
    }
    dfs(1,0);
    printf("%d",f[1][Q]);
}