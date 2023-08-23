#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,ans,ansl,t,h=1e9,x,y,kx=-1,ky=-1;
char map[105][105];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int PCWkeyizou[105][105];
struct node{
    int x,y,n;
};
queue <node> Q;
void bfs(){
	while(!Q.empty()){
		int l=Q.front().x,r=Q.front().y,u=Q.front().n;
		PCWkeyizou[l][r]=u;
		Q.pop();
		for(int i=0;i<=3;i++){
			int X1=l+dir[i][1],Y1=r+dir[i][0];
			if(PCWkeyizou[X1][Y1]==-1 && X1>=1 && X1<=n && Y1>=1 && Y1<=m && map[X1][Y1]!='*'){
				Q.push({X1,Y1,u+1});
			}
		}
	}
}
int main(){
	cin>>n>>m>>t; 
	memset(PCWkeyizou,-1,sizeof(PCWkeyizou)); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			if(map[i][j]=='@'){
				x=i,y=j;
			}
			else if(map[i][j]=='#'){
				kx=i,ky=j;
				map[i][j]='*';
			}
		}
	}
    Q.push({x,y,0});
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(PCWkeyizou[i][j]!=-1 && map[i][j]=='$'){
				ans++;
				if(PCWkeyizou[i][j]<h) h=PCWkeyizou[i][j];
			}
		}
	} 
	PCWkeyizou[kx][ky]=100000000;
	for(int i=0;i<=3;i++){
        if(PCWkeyizou[kx+dir[i][1]][ky+dir[i][0]]>=0){
            PCWkeyizou[kx][ky]=min(PCWkeyizou[kx][ky],PCWkeyizou[kx+dir[i][1]][ky+dir[i][0]]+1);
        }
    }
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(PCWkeyizou[i][j]==h && map[i][j]=='$'){
                cout<<j<<" "<<i<<endl;
            }
		}
	}
	if(PCWkeyizou[kx][ky]<=t&&PCWkeyizou[kx][ky]!=-1&&kx!=-1&&ky!=-1){
        cout<<"PCW NB!!!";
    }else{
        cout<<"SINB PCW!!!";
    }
	return 0;
} 