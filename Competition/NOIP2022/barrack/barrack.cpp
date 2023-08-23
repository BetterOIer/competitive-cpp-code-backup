#include<iostream>
#include<vector>
using namespace std;
const int maxn = 10;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
int n,m;
long long ans=0;
vector<int>ro[maxn];
int whi[maxn],tot=0;
int bel[maxn],vis[maxn],low[maxn],fat[maxn],dfn[maxn],cnt=0;
void trans(int x){
	int pos=1;
	while(x){
		if((x&1)==1){
			whi[++tot]=pos;
		}
		x>>=1;
		pos++;
	}
}
struct EDGE{
	int n1;
	int n2;
};
vector<EDGE>edge;
int find(int pos){
	return (bel[pos]==pos? pos:bel[pos]=find(bel[pos]));
}
void psh(int pos,int ro){
	while(pos!=ro){
		edge.push_back((EDGE){pos,fat[pos]});
		pos=fat[pos];
	}
}
void work(int fa,int pos){
	vis[pos]=true;
	bel[pos]=fa;
	fat[pos]=fa;
	low[pos]=pos;
	dfn[pos]=++cnt;
	for(int to:ro[pos]){
		if(fa==to)continue;
		if(!vis[to]){
			work(pos,to);
			low[pos]=min(low[to],low[pos]);
		}
		else low[pos]=min(dfn[to],low[pos]);
	}
	if(low[pos]!=find(pos)){
		psh(low[pos],find(pos));
	}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i = 1,u,v;i<=m;i++){
		u=read(),v=read();
		ro[u].push_back(v);
		ro[v].push_back(u);
	}
	int ctal=(1<<n)-1;
	for(int i = 1;i<=ctal;i++){
		trans(i);
		work(1,1);
		int left=m-edge.size();
		ans+=(1<<left);
		edge.clear();
		for(int i = 1;i<=n;i++){
			bel[i]=vis[i]=low[i]=fat[i]=dfn[i]=0;
		}
		tot=0;cnt=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}