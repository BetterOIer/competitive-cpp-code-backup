#include<iostream>
using namespace std;
int n,m,a[110],f[10010];
int main()
{
   cin>>n>>m;
   for(int i=1;i<=n;i++)
     cin>>a[i];
   f[0]=1;
   for(int i=1;i<=n;i++)
     for(int j=m;j>=a[i];j--)
     	  f[j]=f[j]+f[j-a[i]];
   cout<<f[m];
   return 0;
}