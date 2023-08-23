#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=1e5+5,Maxm=1e6+5;
struct Node{int x,y,z,num;}node[Maxn];
struct Edge{int u,v,w;}graph[Maxm];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
bool cmpx(Node n1,Node n2) {return n1.x<n2.x;}
bool cmpy(Node n1,Node n2) {return n1.y<n2.y;}
bool cmpz(Node n1,Node n2) {return n1.z<n2.z;}
bool cmpw(Edge e1,Edge e2) {return e1.w<e2.w;}
int fa[Maxn],n,m;
long long ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {fa[find(x)]=find(y);}
void kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	int count=0;
	sort(graph+1,graph+m+1,cmpw);
	for(int i=1;i<=m;i++){
		Edge e=graph[i];
		int u=e.u,v=e.v,w=e.w;
		if(find(u)!=find(v)) {
			merge(u,v);
			ans+=w;
			count++;
			if(count==n-1) return;
		}
	}
}
void add(int u,int v,int w){
	graph[++m].u=u;
	graph[m].v=v;
	graph[m].w=w;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) node[i].x=read(),node[i].y=read(),node[i].z=read(),node[i].num=i;
	sort(node+1,node+n+1,cmpx);for(int i=1;i<n;i++) add(node[i].num,node[i+1].num,node[i+1].x-node[i].x);
	sort(node+1,node+n+1,cmpy);for(int i=1;i<n;i++) add(node[i].num,node[i+1].num,node[i+1].y-node[i].y);
	sort(node+1,node+n+1,cmpz);for(int i=1;i<n;i++) add(node[i].num,node[i+1].num,node[i+1].z-node[i].z);
	kruskal();
	cout<<ans;
	return 0;
}
