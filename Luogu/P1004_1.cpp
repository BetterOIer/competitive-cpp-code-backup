#include<bits/stdc++.h>
using namespace std;
int a[11][11],n,p[11];
long long maxx,ans;
void dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[j]=max(p[j-1]+a[i][j],p[j]+a[i][j]);
		}
	}
}
void dfs(int x,int y){
	if(x==n&&y==n){
		dp();
		ans=max(ans,p[n]+maxx);
		memset(p,0,sizeof(p));
		return;
	}
	if(x>n||y>n)return;
	int r=a[x][y];
	maxx+=r;
	a[x][y]=0;
	dfs(x+1,y);
	dfs(x,y+1);
	a[x][y]=r;
	maxx-=r;
}
int main(){
	cin>>n;
	int qx,qy,numb;
	while(cin>>qx>>qy>>numb){
		if(qx==0&&qy==0&&numb==0)break;
		a[qx][qy]=numb;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
} 