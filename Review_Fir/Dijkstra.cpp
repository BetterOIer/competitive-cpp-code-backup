/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int to;
    int val;
};
bool operator < (const node a,const node b){
    return a.val>b.val;
}//! Priority_queue needs to swap < and >
priority_queue<node>q;
vector<node>ro[100006];
int dis[100005];
int n,m,s;
bool vis[100005];
int main(){
    n=read(),m=read(),s=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    for(int i = 1;i<=n;i++){
        dis[i]=2147483647;
    }
    q.push((node){s,0});
    dis[s]=0;
    while(q.size()){
        node now = q.top();
        q.pop();
        if(vis[now.to])continue;
        vis[now.to]=true;
        if(ro[now.to].empty())continue;
        for(node to:ro[now.to]){
            if(to.val+now.val<dis[to.to]){
                dis[to.to]=to.val+now.val;
                q.push((node){to.to,dis[to.to]});
            }
        }
    }
    for(int i = 1;i<=n;i++) cout<<dis[i]<<" ";
    return 0;
}