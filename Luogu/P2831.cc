#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int T,n,g[101][101],cac[101],tot,f[262155];
double x[101],y[101];
int main(){
    T=read();
	while(T--){
		n=read();x[1]=read();
		for(int i = 1;i<=n;i++){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		memset(f,0x3f,sizeof f);
		memset(g,0,sizeof g);
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (fabs((y[j]/x[j])-(y[i]/x[i]))<1e-10||fabs(x[i]-x[j])<1e-10){
					g[i][j]=-1;continue;
				}else{
					double B=(y[i]*x[j]*x[j]-y[j]*x[i]*x[i])/(x[j]*x[j]*x[i]-x[i]*x[i]*x[j]);
					double A=(y[i]-B*x[i])/(x[i]*x[i]);
					if (A>=0){
						g[i][j]=-1;continue;
					}
					for (int k=1;k<=n;k++){
						if (fabs(A*x[k]*x[k]+B*x[k]-y[k])<1e-10) g[i][j]+=(1<<(k-1));
					}
				}
			}
		}
		f[0]=0;
		for (int i=1;i<(1<<n);i++){
			tot=0;
			for (int j=1;j<=n;j++){
				if ((i>>(j-1))&1) cac[++tot]=j;
			}
			f[i]=1+f[i^(i&-i)];
			for (int j=2;j<=tot;j++){
				int zt=g[cac[1]][cac[j]];
				if (zt==-1) continue;
				f[i]=min(f[i],1+f[i^(i&zt)]);
            }
		}
		cout<<f[(1<<n)-1]<<endl;
	}
	return 0;
}
