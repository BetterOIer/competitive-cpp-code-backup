#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
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
vector <node> road_up[1005];
vector <node> road_down[1005];
int vis[1005],pre[1005];
int dis_up[1005],dis_down[1005];
long long res;
int main(){
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        road_up[u].push_back(node{v,w});
        road_down[v].push_back(node{u,w});
    }
    for(int i = 1;i<=n;i++){
        dis_up[i]=2147483647;
        dis_down[i]=2147483647;
    }
    dis_up[1]=0;
    dis_down[1]=0;
    q.push((Qnode){0,1});
    while(!q.empty()){
        Qnode now =q.top();q.pop();
        int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(road_up[u].size()){
            for(int i = 0;i<=road_up[u].size()-1;i++){
                if(dis_up[road_up[u][i].to]>dis_up[u]+road_up[u][i].val){
                    dis_up[road_up[u][i].to]=dis_up[u]+road_up[u][i].val;
                    pre[road_up[u][i].to]=u;
                    q.push((Qnode){dis_up[road_up[u][i].to],road_up[u][i].to});
                    res+=dis_up[road_up[u][i].to];
                }
            }
        }
    }
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    q.push((Qnode){0,1});
    while(!q.empty()){
        Qnode now =q.top();q.pop();
        int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(road_down[u].size()){
            for(int i = 0;i<=road_down[u].size()-1;i++){
                if(dis_down[road_down[u][i].to]>dis_down[u]+road_down[u][i].val){
                    dis_down[road_down[u][i].to]=dis_down[u]+road_down[u][i].val;
                    pre[road_down[u][i].to]=u;
                    q.push((Qnode){dis_down[road_down[u][i].to],road_down[u][i].to});
                    res+=dis_down[road_down[u][i].to];
                }
            }
        }
    }
    printf("%d ",res);
    return 0;
}