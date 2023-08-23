#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector <int> road[100004];
int fa[100005];
bool can[100005];
int dep[100005];
int u,v;
int dfs(int now){
    int ans=0,deep=0;
    if(road[now].size()==1&&road[now][0]==fa[now]){
        can[now]=true;
        dep[now]=0;
        return 1;
    }
    for(int i = 0;i<=road[now].size()-1;i++){
        if(road[now][i]==fa[now]) continue;
        fa[road[now][i]]=now;
        ans+=dfs(road[now][i]);
        deep=max(deep,dep[road[now][i]]);
        if(dep[road[now][i]]>=v){
            can[now]=false;
        }
    }
    dep[now]=deep+1;
    if(can[now]==true) return ans+1;
    return ans;
}
int main(){
    freopen("astralability.in","r",stdin);
    freopen("astralability.out","w",stdout);
    int n=read(),q=read();
    for(int i = 1;i<=n-1;i++){
        u=read(),v=read();
        road[u].push_back(v);
        road[v].push_back(u);

    }
    for(int i = 1;i<=q;i++){
        u=read(),v=read();
        memset(can,true,sizeof(can));
        memset(fa,0,sizeof(fa));
        memset(dep,0,sizeof(dep));
        cout<<dfs(u)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}