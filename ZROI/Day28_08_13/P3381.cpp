/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct EDGE{
    int to;
    int cost;
    int val;
    int nex;
}edge[100004];
int n,m,s,t;
int flow, cost;
int head[5003],idx=1;
int dis[5003],lim[5003],pre[5003];
bool vis[5003];
void add(int a, int b, int c, int d){
    edge[++idx] = {b,c,d,head[a]};
    head[a]=idx;
}
bool spfa(){
    memset(dis,0x3f,sizeof dis);
    memset(lim,0,sizeof lim);
    queue<int>q;q.push(s);
    dis[s]=0,lim[s]=1e9,vis[s]=true;
    while(q.size()){
        int now = q.front();vis[now]=false;q.pop();
        for(int i= head[now];i;i=edge[i].nex){
            int to = edge[i].to;
            if(dis[to]>dis[now]+edge[i].val && edge[i].cost){
                dis[to] = dis[now]+edge[i].val;
                lim[to] = min(lim[now],edge[i].cost);
                pre[to] = i;
                if(!vis[to]){
                    q.push(to),vis[to]=true;
                }
            }
        }
    }
    return lim[t]>0;
}
void EK(){
    while(spfa()){
        for(int pre_po = t;pre_po!=s;){
            int pre_li = pre[pre_po];
            edge[pre_li].cost -=lim[t];
            edge[pre_li^1].cost +=lim[t];
            pre_po=edge[pre_li^1].to;
        }
        flow+=lim[t];
        cost+=lim[t]*dis[t];
    }
}
int main(){
    n=read(),m=read(),s=read(),t=read();
    for(int i = 1,a,b,c,d;i<=m;i++){
        a=read(),b=read(),c=read(),d=read();
        add(a,b,c,d),add(b,a,0,-d);
    }
    EK();
    cout<<flow<<" "<<cost<<endl;
    return 0;
}