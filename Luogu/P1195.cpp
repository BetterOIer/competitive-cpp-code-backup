#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,k;
struct EDGE{
    int node1;
    int node2;
    int cost;
};
EDGE ro[10004];
int fa[105];
bool cmp(EDGE a,EDGE b){
	return a.cost<b.cost;
}
int find(int pos){return pos==fa[pos]? pos:fa[pos]=find(fa[pos]);}
void join(int node1,int node2){
    fa[find(node1)]=find(node2);
}
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1;i<=n;i++) fa[i]=i;
    int all=0;
    int need = 0;
    for(int i = 1;i<=m;i++){
        ro[i].node1=read(),ro[i].node2=read(),ro[i].cost=read();
    }
    sort(ro+1,ro+m+1,cmp);
    for(int i = 1;i<=m&&need<=n-k;i++){
        if(find(ro[i].node1)==find(ro[i].node2))continue;
        
        join(ro[i].node1,ro[i].node2);
        ++need;
        all+=ro[i].cost;
        if(need>=n-k) break;
    }
    if(need>=n-k) cout<<all;
	else cout<<"No Answer";
	return 0;
}