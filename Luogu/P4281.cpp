#include<iostream>
#include<vector>
using namespace std;
vector <int> po[500005];
int depth[500001], fa[500001][22], lg[500001],len[500001];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void dfs(int now, int fath) {
	fa[now][0] = fath; depth[now] = depth[fath] + 1;
	for(int i = 1; i <= lg[depth[now]]; ++i)
		fa[now][i] = fa[fa[now][i-1]][i-1];
    for(int i = 0;i<=po[now].size()-1;i++){
        if(po[now][i]!=fath){
            len[po[now][i]]=len[now]+1;
            dfs(po[now][i],now);
        }
    }
}
int LCA(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(;depth[x]>depth[y];){
        x = fa[x][lg[depth[x]-depth[y]] - 1];
    }
    if(x==y)return x;
    for(int k = lg[depth[x]] - 1; k >= 0; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}
int main(){
    int n=read(),m=read(),g1,g2,g3;
    for(int i = 1;i<n;i++){
        g1=read(),g2=read();
        po[g1].push_back(g2);
        po[g2].push_back(g1);
    }
    for(int i = 1;i<=n;i++)lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    dfs(1,0);
    for(int i = 1;i<=m;i++){
        g1=read(),g2=read(),g3=read();
        int p1=LCA(g1,g2),p2=LCA(g1,g3),p3=LCA(g2,g3);
        if(p1==p2) swap(p1,p3);
        else if(p1==p3) swap(p1,p2);
        cout<<p1<<" "<<len[g1]+len[g2]+len[g3]-len[p1]-len[p2]-len[p3]<<endl;
    }
}