#include<iostream>
#include<cstdio> 
#include<cmath>
using namespace std;
int G[100005][40],a,x,nishishabi,n,m,p,len,l,r;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {	
        scanf("%d",&a);
        G[i][0]=a;
    }
    nishishabi=(int)(log(n)/log(2));
    for(int j=1;j<=nishishabi;j++)
        for (int i=1;i<=n-(1<<j)+1;i++)
    		G[i][j]=max(G[i][j-1],G[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&l,&r);
  		p=(int)(log(r-l+1)/log(2));
        printf("%d\n",max(G[l][p],G[r-(1<<p)+1][p]));
    }
    return 0;
}
