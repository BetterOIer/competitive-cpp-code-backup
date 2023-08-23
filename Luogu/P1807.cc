#include<iostream>
#include<queue>
using namespace std;
int in[1505],dis[1505];
vector<int>g[1505];
vector<int>d[1505];
queue <int> Q;
int main(){
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>u>>v>>w;
        in[v]++;
        g[u].push_back(v);
		d[u].push_back(w);
    }
    for(int i = 2;i<=n;i++){
        if(!in[i]) Q.push(i);
        dis[i]=-1000000000;
    }
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        for(int i=0;i<g[now].size();i++){
            if(!--in[g[now][i]]) Q.push(g[now][i]);
        }
    }
    Q.push(1);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        for(int i= 0;i<g[now].size();i++){
            if(dis[g[now][i]]<dis[now]+d[now][i]) dis[g[now][i]]=dis[now]+d[now][i];
            if(!--in[g[now][i]]) Q.push(g[now][i]);
        }
    }
    if(dis[n]==-1e9)cout<<-1;
    else cout<<dis[n];
}