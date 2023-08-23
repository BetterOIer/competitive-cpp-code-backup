#include<iostream>
#include<vector>
using namespace std;
vector <int> po[500005];
int depth[500001], fa[500001][22], lg[500001];
int a[100006],b[100006],dix[100006];
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
        if(po[now][i]!=fath) dfs(po[now][i],now);
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
int dist(int a,int b){
    return depth[a]+depth[b]-2*depth[LCA(a,b)];
}
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int n=read(),m=read(),g1,g2;
    for(int i = 1;i<n;i++){
        g1=read(),g2=read();
        po[g1].push_back(g2);
        po[g2].push_back(g1);
    }
    for(int i = 1;i<=n;i++)lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    dfs(1,0);
    for(;m--;){
        int t=read(),i;
        for(i = 1;i<=t;i++){
            a[i]=read(),b[i]=read();
            dix[i]=dist(a[i],b[i]);
            for(int j = 1;j<i;j++){
                int tt=dist(a[i],a[j])+dist(b[i],b[j]);
                int ttt=dist(a[i],b[j])+dist(b[i],a[j]);
                int tttt=dix[i]+dix[j];
                if(tt==ttt||tt==tttt||ttt==tttt)goto nec;
            }
        }
        cout<<"Yes"<<endl;
        continue;
        nec:
        for(i++;i<=t;i++){
            a[i]=read(),b[i]=read();
        }
        cout<<"No"<<endl;
        continue;
    }
}