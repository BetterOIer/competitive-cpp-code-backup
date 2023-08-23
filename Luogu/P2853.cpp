#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector <int> field[1005];
queue <int> Q;
bool vis[1005];
int cow[105],fie[1001],ans=0;
int main(){
    int k,n,m,u,v;
    cin>>k>>n>>m;
    for(int i = 1;i<=k;i++) cin>>cow[i];
    for(int i = 1;i<=m;i++){
        cin>>u>>v;
        field[u].push_back(v);
    }
    for(int i = 1;i<=k;i++){
        memset(vis,false,sizeof(vis));
        vis[cow[k]]=true;
        Q.push(cow[k]);
        while(!Q.empty()){
            int now=Q.front();Q.pop();
            fie[now]++;
            if(field[now].size()){
                for(int w = 0;w<=field[now].size()-1;w++){
                    if(!vis[field[now][w]]){
                        Q.push(field[now][w]);
                        vis[field[now][w]]=true;
                    }
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(fie[i]==k) ans++;
    }
    cout<<ans;
}