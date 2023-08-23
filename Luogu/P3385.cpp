#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct node{
    int to;
    int val;
};
vector <node> ro[2003];
queue <int> Q;
int dist[2003],cnt[2003];
bool vis[2003];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,u,v,w,flag=false;

        memset(dist,0x3f,sizeof(dist));
        memset(cnt,0,sizeof(cnt));
        memset(vis,false,sizeof(vis));

        for(int i = 1;i<=n;i++) ro[i].clear();
        while(!Q.empty())Q.pop();

        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>u>>v>>w;
            if(w>=0) ro[v].push_back((node){u,w});
            ro[u].push_back((node){v,w});
        }
        Q.push(1);
        vis[1]=true;
        dist[1]=0;
        while(!Q.empty()&&(!flag)){
            int np=Q.front();
            vis[np]=false;
            Q.pop();
            if(ro[np].size()){
                for(int i = 0;i<=ro[np].size()-1;i++){
                    int v = ro[np][i].to,w=ro[np][i].val;
                    if(dist[v]>dist[np]+w){
                        dist[v]=dist[np]+w;
                        cnt[v]=cnt[np]+1;
                        if(cnt[v]>=n)
                        {
                            printf("YES\n");
                            flag=true;
                            break;
                        }
                        if(!vis[v])
                        {
                            vis[v]=1;Q.push(v);
                        }
                    }
                }
            }
        }
        if(!flag) printf("NO\n");
    }
}