#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
struct EDGE{
    int node1;
    int node2;
    int val;
    bool operator < (const EDGE &i)const{
        return val<i.val;
    }
}edge[300005],unused[200005];
struct NODE{
    int to;
    int val;
};
int fa[100005],cnt;
long long sum=0;
vector<NODE>ro[100005];
int dep[100005],tf[100005][20],mx[100005][20],me[100005][20];
int find(int pos){return pos==fa[pos]? pos:fa[pos]=find(fa[pos]);}
void join(int node1,int node2){fa[find(node1)]=find(node2);}
void dfs(int pos,int fa){
    dep[pos]=dep[fa]+1;
    tf[pos][0]=fa;
    for(NODE to:ro[pos]){
        if(to.to==fa)continue;
        mx[to.to][0] = to.val;
        dfs(to.to,pos);
    }
}
int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 18; i >= 0; i--) if (dep[ tf[x][i] ] >= dep[y] ) x = tf[x][i];
    if (x == y) return x;
    for (int i = 18; i  >= 0; i--) if (tf[x][i] != tf[y][i]) x = tf[x][i], y = tf[y][i];
    return tf[x][0];
}
int findmax(int x,int lca,int val){
    long long ans=0;
    for (int i = 1; i <= cnt; i++){
        int x = unused[i].node1, y = unused[i].node2, z = unused[i].val;
        int lca = LCA(x, y);
        int lmx = findmax(x, lca, z), rmx = findmax(y, lca, z);
        if (max(lmx, rmx) != z)  ans = min(ans, sum + z - max(lmx, rmx));
    }
    return ans;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        edge[i].node1=read();
        edge[i].node2=read();
        edge[i].val=read();
    }
    sort(edge+1,edge+m+1);
    for(int i = 1;i<=n;i++)fa[i]=i;
    for(int i = 1;i<=m;i++){
        if(find(edge[i].node1)==find(edge[i].node2)){
            unused[++cnt]=edge[i];
        }else{
            sum+=edge[i].val;
            join(edge[i].node1,edge[i].node2);
            ro[edge[i].node1].push_back((NODE){edge[i].node2,edge[i].val});
            ro[edge[i].node2].push_back((NODE){edge[i].node1,edge[i].val});
        }
    }
    dfs(1,0);
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            int topf = tf[j][i - 1];
            tf[j][i] = tf[topf][i - 1];
            mx[j][i] = max(mx[j][i - 1], mx[topf][i - 1]);
            me[j][i] = max(me[j][i - 1], me[topf][i - 1]);
            if (mx[j][i - 1] > mx[topf][i - 1]) me[j][i] = max(me[j][i], mx[topf][i - 1]);
            else if (mx[j][i - 1] < mx[topf][i - 1]) me[j][i] = max(me[j][i], mx[j][i - 1]);
        }
    }
    long long ans = 9223372036854775807ll;
    for (int i = 1; i <= cnt; i++) {
        int x = unused[i].node1, y = unused[i].node2, z = unused[i].val;
        int lca = LCA(x, y);
        int lmx = findmax(x, lca, z), rmx = findmax(y, lca, z);
        if (max(lmx, rmx) != z)  ans = min(ans, sum + z - max(lmx, rmx));
    }
    printf("%lld", ans);
}
