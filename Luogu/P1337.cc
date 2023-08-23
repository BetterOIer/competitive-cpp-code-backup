#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct things{int x,y,w;} a[1007];
int n;
double X,Y,ans,ansx,ansy;
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double cal()
{
	double res=0;
	for(int i=1;i<=n;++i)
		res+=dis(a[i].x,a[i].y,X,Y)*a[i].w;
	return res;
}
int main()
{
	srand(time(0));
	n=read();
	for(int i=1;i<=n;++i)
		a[i].x=read(),a[i].y=read(),a[i].w=read(),X+=a[i].x,Y+=a[i].y;
	X/=n,Y/=n;
	ans=cal();
	int per_time=0;
	do
	{
		for(double temper=4e3;temper>1e-13;temper*=0.999)
		{
			double xx=X,yy=Y;
			X+=temper*((rand()<<1)-RAND_MAX);
			Y+=temper*((rand()<<1)-RAND_MAX);
			double res=cal();
			double delta=res-ans;
			if(delta<0) ans=res,ansx=X,ansy=Y;
			else if(RAND_MAX*exp(-delta/temper)<=rand()) X=xx,Y=yy;
		}
		if(!per_time) per_time=clock();
	}
	while(clock()+per_time<0.95*CLOCKS_PER_SEC);
	printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}