#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
inline int read(){
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x; 
}
struct Edge{
	int to,next;
}edge[400005];
int ent,n,m,q,head[200005];
int dis[200005];
bool vis[200005];
priority_queue<PII,vector<PII>,greater<PII> >Q;
inline void add(int u,int v){
	edge[++ent].to=v;
	edge[ent].next=head[u];
	head[u]=ent;
	return;
}
inline void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	Q.push({0,1});
	while(!Q.empty()){
		int x=Q.top().second;
		Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				Q.push({dis[y],y});
			}
		}
	}
	return;
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v+n),add(v,u+n),add(u+n,v),add(v+n,u); 
	}
	dijkstra();
	while(q--){
		int x=read(),y=read();
		if(y%2){
			if(dis[x+n]<=y)puts("Yes");
			else puts("No");
		}else{
			if(dis[x]<=y)puts("Yes");
			else puts("No");
		}
	}
	return 0;
}