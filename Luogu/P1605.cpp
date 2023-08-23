#include<iostream>
using namespace std;
int WOCAO[6][6],FUCK[6][6];
int zx,zy,sx,sy,ans=0,n,m;
void PCWNASYFUNXGSUNFMAGSGFVNFGSJ(int x,int y){
	if(x==zx&&y==zy){
		ans++;
		return;
	}
	else{
	if(WOCAO[x+1][y]==1&&FUCK[x+1][y]==0){
		WOCAO[x+1][y]=0;
		PCWNASYFUNXGSUNFMAGSGFVNFGSJ(x+1,y);
		WOCAO[x+1][y]=1;
	}
	if(WOCAO[x-1][y]==1&&FUCK[x-1][y]==0){
		WOCAO[x-1][y]=0;
		PCWNASYFUNXGSUNFMAGSGFVNFGSJ(x-1,y);
		WOCAO[x-1][y]=1;
	}
	if(WOCAO[x][y+1]==1&&FUCK[x][y+1]==0){
		WOCAO[x][y+1]=0;
		PCWNASYFUNXGSUNFMAGSGFVNFGSJ(x,y+1);
		WOCAO[x][y+1]=1;
	}
	if(WOCAO[x][y-1]==1&&FUCK[x][y-1]==0){
		WOCAO[x][y-1]=0;
		PCWNASYFUNXGSUNFMAGSGFVNFGSJ(x,y-1);
		WOCAO[x][y-1]=1;
	}
	}
}
int main(){
	int t;
	cin>>n>>m>>t;
	for(int ix=1;ix<=n;ix++)
        for(int iy=1;iy<=m;iy++)
            WOCAO[ix][iy]=1;
	cin>>sx>>sy>>zx>>zy;
	WOCAO[sx][sy]=0;
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		FUCK[x][y]=4;
	}
	PCWNASYFUNXGSUNFMAGSGFVNFGSJ(sx,sy);
	cout<<ans;
	return 0;
}