#include<iostream>
#include<queue>
using namespace std;
const int inf =1 <<29,N =8010,M=1200005;
long long head[N],ver[M],edge[M],Next[M],v[N],incf[N],pre[N];
long long n,m,s,t,tot,maxflow;
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
    ver[++tot]=x,edge[tot]=0,Next[tot]=head[y],head[y]=tot;
}
bool bfs(){
    for(int i = 0;i<=N-1;i++) v[i]=0;
    queue<int>q;
    q.push(s);v[s]=1;
    incf[s]=inf;
    while (q.size()){
        int x=q.front();q.pop();
        for (int i= head[x];i;i=Next[i])
            if (edge[i]){
                int y=ver[i];
                if (v[y])continue;
                incf[y]=min(incf[x],edge[i]);
                pre[y]=i;
                q.push(y),v[y]=1;
                if (y ==t)return 1;
            }
    }
    return 0;
}
void update(){
    int x=t;
    while (x !=s){
        int i= pre[x];
        edge[i]-=incf[t];
        edge[i^1]+=incf[t];
        x= ver[i^1];
    }
    maxflow +=incf[t];
}

int main(){
    cin >>m >>n>>s>>t;
    tot =1;maxflow =0;
    for (int i =1;i <=n;i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        add(x,y,c);
    }
    while (bfs())update();
    cout<<maxflow<<endl;
}