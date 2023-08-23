#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int to;
    int val;
    int ctdir;
};
struct Qnode{
    int w;
    int po;
    int ctdir;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
priority_queue<Qnode>q;
vector <node> road[20005];
int vis[1005],pre[1005];
long long dis[1005];
int ctrl[25];
int main(){
    //freopen("updown.in","r",stdin);
    //freopen("updown.out","w",stdout);
    int n,m,I;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d",&ctrl[i]);
        if(ctrl[i]==0) I=i;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(i+ctrl[j]<=n&&i+ctrl[j]>=1){
                road[i].push_back(node{i+ctrl[j],2*abs(ctrl[j]),j});
            }
        }
    }
    for(int i = 1;i<=n;i++) dis[i]=9223372036854775807;
    dis[1]=0;
    q.push((Qnode){0,1,I});
    while(!q.empty()){
        Qnode now =q.top();q.pop();
        int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
        if(road[u].size()){
            for(int i = 0;i<=road[u].size()-1;i++){
                if(dis[road[u][i].to]>dis[u]+road[u][i].val+abs(road[u][i].ctdir-now.ctdir)){
                    dis[road[u][i].to]=dis[u]+road[u][i].val+abs(road[u][i].ctdir-now.ctdir);
                    pre[road[u][i].to]=u;
                    q.push((Qnode){dis[road[u][i].to],road[u][i].to,road[u][i].ctdir});
                }
            }
        }
    }
    if(dis[n]==9223372036854775807) printf("-1");
    else printf("%d",dis[n]);
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}