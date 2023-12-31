#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int to;
    int val;
};
struct Qnode{
    int w;
    int po;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
priority_queue<Qnode>q;
vector <node> road[100004];
int vis[100004],pre[100004];
int dis[100004];
int main(){
    int n,m,f,u,v,w;
    scanf("%d%d%d",&n,&m,&f);
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        road[u].push_back(node{v,w});
    }
    for(int i = 1;i<=n;i++) dis[i]=2147483647;
    dis[f]=0;
    q.push((Qnode){0,f});
    while(!q.empty()){
        Qnode now =q.top();q.pop();
        int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(road[u].size()){
            for(int i = 0;i<=road[u].size()-1;i++){
                if(dis[road[u][i].to]>dis[u]+road[u][i].val){
                    dis[road[u][i].to]=dis[u]+road[u][i].val;
                    pre[road[u][i].to]=u;
                    q.push((Qnode){dis[road[u][i].to],road[u][i].to});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}