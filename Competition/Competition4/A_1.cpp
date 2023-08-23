#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,x[10005],y[10005],ans=0,rex,rey;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",x+i,y+i);
	sort(x+1,x+n+1); sort(y+1,y+n+1);
	for(int i=1;i<=n;i++) x[i]-=i;
	sort(x+1,x+n+1);
	if(!n%2)
	{
		rex=(x[n/2]+x[n/2+1])/2;
		rey=(y[n/2]+y[n/2+1])/2;
	}
	else
	{
		rex=x[n/2+1];
		rey=y[n/2+1];
	}
	for(int i=1;i<=n;i++) ans+=abs(x[i]-rex)+abs(y[i]-rey);
	printf("%d",ans);
	return 0;
} 
