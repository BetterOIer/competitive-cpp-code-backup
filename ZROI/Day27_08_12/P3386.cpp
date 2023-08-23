/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,e,ans=0;
vector<int>ro[502];
bool vis[502];
int match[502];
bool dfs(int pos){
    for(int to:ro[pos]){
        if(vis[to]) continue;
        vis[to]=true;
        if(!match[to]||dfs(match[to])){
            match[to]=pos;
            return true;
        }
    }
    return false;
}
int main(){
    n=read(),m=read(),e=read();
    for(int i = 1,u,v;i<=e;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        //ro[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        memset(vis, false ,sizeof vis);
        if(dfs(i))ans++;
    }
    cout<<ans<<endl;
    return 0;
}