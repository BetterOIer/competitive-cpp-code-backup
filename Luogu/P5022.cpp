#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn = 1000005;
vector<int>ro[maxn];
pair<int,int>R[maxn];
int n,m;
namespace ring{
    int du, dv,cnt,better;
    bool vis[maxn];
    vector<int>bettest(maxn,maxn);
    bool dfs(int now){
        if(!better){
            if(now>bettest[cnt]) return true;
            if(now<bettest[cnt]) better=-1;
        }
        vis[now]=true;
        bettest[cnt++]=now;
        for(auto i:ro[now]){
            if(vis[i]||(now==du&&i==dv)||(now==dv&&i==du))continue;
            if(dfs(i))return true;
        }
        return false;
    }
    int main(){
        for(int i = 1;i<=m;i++){
            du=R[i].first;
            dv=R[i].second;
            for(int i = 1;i<=n;i++)vis[i]=false;
            cnt=better=0;
            dfs(1);
        }
        for(int i = 0;i<n;i++)cout<<bettest[i]<<" ";
        return 0;
    }
}
/* namespace ring2{
    bool vis[maxn],huan[maxn];
    int End,rt=1,inf=0x3f3f3f;
    bool dfs1(int x,int fa){
        if(vis[x]){
            End=x;
            return true;
        }
        vis[x]=1;
        for(auto i:ro[x]){
            if(i==fa) continue;
            if(dfs1(i,x)){
                huan[x]=true;
                return x!=End;
            }
        }
        return false;
    }
    void dfs2(int now,int fa,int base=0x3f3f3f){
        if(!huan[now]){
            if(!vis[now]){
                cout<<now<<" ";
                vis[now]=true;
            }
            for(auto i:ro[now]){
                if(i==fa)continue;
                dfs2(i,now,base);
            }
        }else{
            if(now>base)return;
            if(!huan[fa])rt=now;
            if(!vis[now]){
                cout<<now<<" ";
                vis[now]=true;
            }
            int se=0,fi=0;
            if(now==rt)for(auto i:ro[now]){
                if(vis[i]||i==fa)continue;
                se=fi;
                fi=i;
                if(se) dfs2(se,now,fi);
            }
            else {
                for(auto i:ro[now]){
                    if(vis[i]||i==fa)continue;
                    dfs2(i,now,base); 
                }
            }
        }
    }
    int main(){
        dfs1(1,0);
        for(int i = 1;i<=n;i++)vis[i]=false;
        dfs2(1,0,inf);
        return 0;
    }
} */

namespace tree{
    void dfs(int now,int fa){
        cout<<now<<" ";
        for(auto i:ro[now]){
            if(i==fa)continue;
            dfs(i,now);
        }
    }
    int main(){
        dfs(1,0);
        return 0;
    }
}

int main(){
    n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read();v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
        R[i]=make_pair(u,v);
    }
    for(int i = 1;i<=n;i++) sort(ro[i].begin(),ro[i].end());
    if(m+1==n) tree::main();
    else ring::main();
    return 0;
}