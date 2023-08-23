#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
};
struct Qnode{
    int w;
    int po;
    inline bool operator <(const Qnode &x)const{
        return w>x.w;
    }
};
priority_queue<Qnode>q;
vector <node> road[3004];
int vis[3][3004],pre[3][3004];
int dis[3][3004];
int ans=1e9;
int main(){
    int n=read(),m=read(),u,v,w,s1,t1,s2,t2;
    for(int i = 1;i<=m;i++){
    	u=read(),v=read();
        road[u].push_back((node){v});
        road[v].push_back((node){u});
    }
    s1=read();
	t1=read();
	s2=read();
	t2=read();

	for(int i = 1;i<=n;i++) dis[0][i]=2147483647;
	dis[0][1]=0;
	q.push((Qnode){0,1});
	while(!q.empty()){
		Qnode now=q.top();q.pop();
		int u=now.po;
        if(vis[0][u])continue;
        vis[0][u]=1;
		if(road[u].size()){
			for(int i = 0;i<=road[u].size()-1;i++){
				if(dis[0][road[u][i].to]>dis[0][u]+1){
					dis[0][road[u][i].to]=dis[0][u]+1;
					pre[0][road[u][i].to]=u;
					q.push((Qnode){dis[0][road[u][i].to],road[u][i].to});
				}
			}
		}
	}
    if(t1<dis[0][s1]||t2<dis[0][s2]){
		cout<<-1;
		return 0;
    }
    for(int i = 1;i<=n;i++) dis[1][i]=2147483647;
	dis[1][s1]=0;
	q.push((Qnode){0,s1});
	while(!q.empty()){
		Qnode now=q.top();q.pop();
		int u=now.po;
        if(vis[1][u])continue;
        vis[1][u]=1;
		if(road[u].size()){
			for(int i = 0;i<=road[u].size()-1;i++){
				if(dis[1][road[u][i].to]>dis[1][u]+1){
					dis[1][road[u][i].to]=dis[1][u]+1;
					pre[1][road[u][i].to]=u;
					q.push((Qnode){dis[1][road[u][i].to],road[u][i].to});
				}
			}
		}
	}

    for(int i = 1;i<=n;i++) dis[2][i]=2147483647;
	dis[2][s2]=0;
	q.push((Qnode){0,s2});
	while(!q.empty()){
		Qnode now=q.top();q.pop();
		int u=now.po;
        if(vis[2][u])continue;
        vis[2][u]=1;
		if(road[u].size()){
			for(int i = 0;i<=road[u].size()-1;i++){
				if(dis[2][road[u][i].to]>dis[2][u]+1){
					dis[2][road[u][i].to]=dis[2][u]+1;
					pre[2][road[u][i].to]=u;
					q.push((Qnode){dis[2][road[u][i].to],road[u][i].to});
				}
			}
		}
	}
    for(int i =1;i<=n;i++){
        ans=min(ans,dis[0][i]+dis[1][i]+dis[2][i]);
    }
    cout<<m-ans;
}