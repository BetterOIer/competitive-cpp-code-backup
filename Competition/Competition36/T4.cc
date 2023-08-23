#include<cstdio>
#include<queue>
#include<cstring>
const int N=100010;
const long long inf=1e17;
struct edge{
	edge*net;int to,w;
}e[N],*tot=e,*head[N];
int s,t,n,m,d[N];
long long dis[N];
int pr[N],st[N],cnt;
std::queue<int>q; 
int main(){
	scanf("%d%d%d%d",&s,&t,&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w),*++tot={head[u],v,w},head[u]=tot,d[v]++;
	}
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	for(int i=1;i<=n;i++)dis[i]=-inf;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(edge*i=head[u];i;i=i->net){
			if(dis[i->to]<dis[u]+i->w){
				dis[i->to]=dis[u]+i->w;
				pr[i->to]=u;
			}
			d[i->to]--;
			if(!d[i->to])q.push(i->to);
		}
	}
	printf("%lld\n",dis[t]);
	while(t!=s&&t)st[++cnt]=t,t=pr[t];
	printf("%d ",s);
	for(int i=cnt;i>=1;i--)printf("%d ",st[i]);
	return 0; 
}