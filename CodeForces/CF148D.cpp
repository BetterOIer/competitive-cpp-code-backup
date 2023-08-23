#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 1005
using namespace std;
int w,b;
double f[maxn][maxn];

double dfs(int nw,int nb){
	if(nw==0) return 0.0;
	if(nb==0) return 1.0;
	if(f[nw][nb]>0) return f[nw][nb];
	double ans=0;
	ans+=1.0*nw/(nw+nb);
	if(nb==2)
	ans+=1.0*nb/(nw+nb)*(nb-1)/(nw+nb-1)*dfs(nw-1,nb-2);
	else if(nb>=3)
	ans+=1.0*nb/(nw+nb)*(nb-1)/(nw+nb-1)*
	(1.0*nw/(nw+nb-2)*dfs(nw-1,nb-2)+1.0*(nb-2)/(nw+nb-2)*dfs(nw,nb-3));
	return f[nw][nb]=ans;
}

int main(){
	scanf("%d%d",&w,&b);
	printf("%.9lf",dfs(w,b));
	return 0;
}
