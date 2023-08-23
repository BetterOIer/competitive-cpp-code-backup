#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{int next,to,s;}b[200010];
int n,m,fa[100010],a[100010],ans[100010],tot=0;
int find(int x){return fa[x]==x? x:fa[x]=find(fa[x]);}
void add(int x,int y,int z){b[++tot].next=a[x];a[x]=tot;b[tot].to=y;b[tot].s=z;}
void dfs(int x,int fa){
	int i;
	for(i=a[x];i;i=b[i].next){
		int y=b[i].to;
		if(y==fa) continue;
		if(ans[x]==b[i].s) ans[y]=ans[x]==1?2:1;
		else ans[y]=b[i].s;
		dfs(y,x);
	}
}
int main(){
	n=read(),m=read();
	int i;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int u=find(x),v=find(y);
		if(u!=v) fa[u]=v,add(x,y,z),add(y,x,z);
	}
	ans[1]=1;dfs(1,0);
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}

