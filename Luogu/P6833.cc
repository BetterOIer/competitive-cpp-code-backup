#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	long long x,y,MyDis;
	bool operator < (const node &b)const{
		return MyDis>b.MyDis;
	}
};
long long dt[1001][1001],MyDis[3][1001][1001];
int n,m,a,b,c,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void dijkstra(int k,int sx,int sy){
	priority_queue<node> q;
	q.push((node){sx,sy,dt[sx][sy]});
	bool Havevisited[1001][1001]={0};
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			MyDis[k][i][j]=1e18;
		}
	}
	MyDis[k][sx][sy]=dt[sx][sy];
	while(!q.empty()){
		int x=q.top().x,y=q.top().y;
		q.pop();
		if(Havevisited[x][y]){
			continue;
		}
		Havevisited[x][y]=1;
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(tx<1||tx>n||ty<1||ty>m){
				continue;
			}
			if(MyDis[k][tx][ty]>MyDis[k][x][y]+dt[tx][ty]){
				MyDis[k][tx][ty]=MyDis[k][x][y]+dt[tx][ty];
				q.push((node){tx,ty,MyDis[k][tx][ty]});
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&dt[i][j]);
	dijkstra(0,1,a),dijkstra(1,n,b),dijkstra(2,n,c);
	long long ans=1e18;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=min(ans,MyDis[0][i][j]+MyDis[1][i][j]+MyDis[2][i][j]-2*dt[i][j]);
	printf("%lld",ans);
    return 0;
}
