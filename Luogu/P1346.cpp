#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,start,en;
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
vector <node> road[204];
int vis[204],pre[204];
int dis[204];
int main(){
    scanf("%d%d%d",&n,&start,&en);
    int u,v;
    for(int i=1;i<=n;i++){
        cin>>u;
        for(int j = 1;j<=u;j++){
            cin>>v;
            if(j==1)road[i].push_back(node{v,0});
            else road[i].push_back(node{v,1});
        }
    }
    for(int i = 1;i<=n;i++) dis[i]=2147483647;
    dis[start]=0;
    q.push((Qnode){0,start});
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
    if(dis[en]==2147483647)printf("-1");
    else printf("%d",dis[en]);
    return 0;
}