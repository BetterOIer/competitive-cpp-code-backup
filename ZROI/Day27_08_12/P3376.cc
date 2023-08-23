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
int n,m,s,t,idx=1;
struct EDGE{
    int to;
    int val;
    int nex;
}edge[10005];
int head[202],cur[202],dep[202];
void add(int a,int b,int c){
    edge[++idx]={b,c,head[a]};
    head[a] = idx;
}
bool bfs(){
    memset(dep,0,sizeof dep);
    queue<int>q;
    q.push(s);
    dep[s]=1;
    while(q.size()){
        int now = q.front();q.pop();
        for(int i = head[now];i;i=edge[i].nex){
            int to = edge[i].to;
            if(dep[to]==0 && edge[i].val){
                dep[to]=dep[now]+1;
                if(to==t)return true;
                q.push(to);
            }
        }
    }
    return false;
}
long long dfs(int pos,int lim){
    if(pos==t) return lim;
    long long sum = 0;
    for(int i = cur[pos];i;i=edge[i].nex){
        cur[pos] = i;
        int to = edge[i].to;
        if(dep[to]==dep[pos]+1&&edge[i].val){
            long long now_lim = dfs(to,min(lim,edge[i].val));
            edge[i].val-=now_lim;
            edge[i^1].val+=now_lim;
            sum+=now_lim;
            lim-=now_lim;
            if(lim==0)break;
        }
    }
    if(sum==0)dep[pos]=0;
    return sum;
}
long long dinic(){
    long long flow = 0;
    while(bfs()){
        memcpy(cur,head,sizeof head);
        flow+=dfs(s,1e9);
    }
    return flow;
}
int main(){
    n=read(),m=read(),s=read(),t=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,0);
    }
    cout<<dinic()<<endl;
    return 0;
}