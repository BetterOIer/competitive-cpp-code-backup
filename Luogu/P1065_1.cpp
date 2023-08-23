#include<iostream>
#include<cstdio>
#define fo(i,j,k) for(i=j;i<=k;i++)
using namespace std;
int n,m,ans;
int whe[25][25],tim[25][25],num[405],calc[405],last[25]; 
bool vis[25][10005];
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n*m;i++) scanf("%d",&num[i]);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&whe[i][j]);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&tim[i][j]);
    for(i=1;i<=n*m;i++)
    {
        calc[num[i]]++;
        int p1=num[i],p2=calc[num[i]],w=whe[p1][p2],t=tim[p1][p2],res=0;
        fo(j,last[p1]+1,10000)
        {
            if(vis[w][j]) res=0;
            else res++;
            if(res==t) break;
        }
        int tmp=j;
        fo(j,tmp-t+1,tmp) vis[w][j]=1;
        last[p1]=tmp;
        ans=max(ans,last[p1]);
    }        
    printf("%d\n",ans);
    return 0;
}