#include<iostream>
using namespace std;
inline  int read(){
	register int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,v;
int a[305][305];
int f[2][305][2005];
int p[1000005],w[2005],cnt=0;
int main(){
    register int i,j,k;for(n=read(),m=read(),v=read(),i=1;i<=n;++i) for(j=1;j<=m;++j) a[i][j]=read();
	register int t=0;for(i=1;i^v;++i) !p[(v-1)/i]&&(w[p[(v-1)/i]=++t]=(v-1)/i);
	for(f[1][1][p[(v-1)/a[1][1]]]=i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j) for(k=0;k<=t;++k) f[(i&1)^1][j][k]=0;
		for(j=1;j<=m;++j) for(k=0;k<=t;++k)
			i^n&&((f[(i&1)^1][j][p[w[k]/a[i+1][j]]]+=(f[(i&1)][j][k]))>=1000000007&&(f[(i&1)^1][j][p[w[k]/a[i+1][j]]]-=1000000007)),
			j^m&&((f[(i&1)][j+1][p[w[k]/a[i][j+1]]]+=(f[(i&1)][j][k]))>=1000000007&&(f[(i&1)][j+1][p[w[k]/a[i][j+1]]]-=1000000007));
	}
	printf("%d\n",f[n&1][m][0]);
    return 0;
}