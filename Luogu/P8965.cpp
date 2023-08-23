//*** Le vent se lève, il faut tenter de vivre ***
#include<iostream>
#include<vector>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    long long to;
    long long val;
};
vector<node> ro[1000005];
long long n,q,dis[1000005];
void dfs(long long pos,long long fa){
    for(node to:ro[pos]){
        if(to.to==fa)continue;
        dis[to.to]=dis[pos]^to.val;
		dfs(to.to,pos);
    }
}
int main(){
    n=read(),q=read();
    for(long long i = 1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
    }
    dfs(1,0);
    for(long long i=1,x,y,l,r;i<=q;i++){
		x=read(),y=read(),l=read(),r=read();
		printf("%d\n",((r-l+1)&1?dis[x]^dis[y]:0));
	}
}