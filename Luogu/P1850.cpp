/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
如果只是路过，那我就在终点等你。 --北省
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,m;
long long v,e,dis[305][305];
long long c[2005],d[2005];
double k[2005],f[2005][2005][5],ans=0x3f3f3f3f;
int main(){
	n=read(),m=read(),v=read(),e=read();
	for(long long i=1;i<=n;i++) c[i]=read();
	for(long long i=1;i<=n;i++) d[i]=read();
	for(long long i=1;i<=n;i++) cin>>k[i];
	for(long long i=1;i<=v;i++)for(long long j=1;j<i;j++) dis[i][j]=dis[j][i]=0x3f3f3f3f;
	for(long long i=1,x,y,z;i<=e;i++)x=read(),y=read(),z=read(),dis[y][x]=dis[x][y]=min(dis[x][y],z);
	for(long long k=1;k<=v;k++) for(long long i=1;i<=v;i++) for(long long j=1;j<i;j++) dis[j][i]=dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	for(long long i=1;i<=n;i++) for(long long j=0;j<=m;j++) f[i][j][0]=f[i][j][1]=0x3f3f3f3f;
	f[1][1][1]=f[1][0][0]=0;
	for(long long i=2;i<=n;i++){
		f[i][0][0]=f[i-1][0][0]+dis[c[i-1]][c[i]];
		for(long long j=1;j<=min(i,m);j++)f[i][j][0]=min(f[i-1][j][0]+dis[c[i-1]][c[i]],f[i-1][j][1]+k[i-1]*dis[d[i-1]][c[i]]+(1-k[i-1])*dis[c[i-1]][c[i]]),f[i][j][1]=min(f[i-1][j-1][0]+k[i]*dis[c[i-1]][d[i]]+(1-k[i])*dis[c[i-1]][c[i]],f[i-1][j-1][1]+k[i]*k[i-1]*dis[d[i-1]][d[i]]+k[i]*(1-k[i-1])*dis[c[i-1]][d[i]]+(1-k[i])*k[i-1]*dis[d[i-1]][c[i]]+(1-k[i-1])*(1-k[i])*dis[c[i-1]][c[i]]);
	}
	for(long long i=0;i<=m;i++)ans=min(ans,f[n][i][1]),ans=min(ans,f[n][i][0]);
	printf("%.2lf",ans);
}