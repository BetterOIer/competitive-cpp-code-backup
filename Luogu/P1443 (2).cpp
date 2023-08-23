#include <bits/stdc++.h>
using namespace std;
int n;
long double a[30][2],ShijiDaan[30][30],WEidAimA[(1<<15)+15][18];
long double cc1,dd5,daan;
int bj[30],i,j;

void dfs(int y,int ww,int x,long double ans){
	if(x==n+1) if(daan==0 || daan>ans) {daan=ans;return;}
	for(int g=1;g<=n;g++)
	{
		if(!bj[g])
		{
			int Nbest=ww+(1<<(g-1));
			if(WEidAimA[Nbest][g]!=0)
			if(WEidAimA[Nbest][g]<=ans+ShijiDaan[y][g]) continue;
			bj[g]=1;
			WEidAimA[Nbest][g]=ans+ShijiDaan[y][g];
			dfs(g,Nbest,x+1,WEidAimA[Nbest][g]);
			bj[g]=0;
		}
	}
	return;
}

int main(){
	cin>>n;
	a[0][0]=0;a[0][1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%Lf %Lf",&a[i][0],&a[i][1]);
		for(j=0;j<i;j++)
		{
			cc1=a[i][0]-a[j][0];
			dd5=a[i][1]-a[j][1];
			ShijiDaan[j][i]=sqrt(cc1*cc1+dd5*dd5);
			ShijiDaan[i][j]=ShijiDaan[j][i];
		}
	}
	dfs(0,0,1,0);
	printf("%.2Lf",daan);
	return 0;
}