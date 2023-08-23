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
	bool chosen=false;
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
int vis[3004],pre[3004];
int dis[3004];
int ans=0;
void check(int po){
	if(po==1) return;
	int pr=pre[po];
	if(road[pr][po].chosen==false){
		ans++;
		road[pr][po].chosen=true;
	}
	check(pr);
}
int main(){
    int n=read(),m=read(),u,v,w,s1,t1,s2,t2;
    for(int i = 1;i<=m;i++){
    	u=read(),v=read();
        road[u].push_back(node{v});
    }
	for(int i = 1;i<=n;i++) dis[i]=2147483647;
	dis[1]=0;
	q.push((Qnode){0,1});
	while(!q.empty()){
		Qnode now=q.top();q.pop();
		int u=now.po;
        if(vis[u])continue;
        vis[u]=1;
		if(road[u].size()){
			for(int i = 0;i<=road[u].size()-1;i++){
				if(dis[road[u][i].to]>dis[u]+1){
					dis[road[u][i].to]=dis[u]+1;
					pre[road[u][i].to]=u;
					q.push((Qnode){dis[road[u][i].to],road[u][i].to});
				}
			}
		}
	}
	s1=read();
	t1=read();
	s2=read();
	t2=read();
	if(t1<dis[s1]||t2<dis[s2]){
		cout<<-1;
		return 0;
	}
	check(s1),check(s2);
	cout<<ans;
}