#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
struct sj{
   long long a[4][4];
   sj operator * (const sj &x)const
    {
        sj ans;
        for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++){
            ans.a[i][j]=0;
            for(int k=1;k<=3;k++)
            {
                ans.a[i][j]+=(a[i][k]*x.a[k][j])%1000000007;
                ans.a[i][j]%=1000000007;
            }
        }
        return ans;
    }
}base;
int k,t;
sj fastpo(sj base,int n)
{
    if(n<=1)return base;
    sj ans=base; n--; 
    while(n>0)
    {
        if(n%2==1)
        ans=ans*base;
        n/=2;
        base=base*base;
    }
    return ans;
}
signed main()
{
    memset(base.a,0,sizeof(base.a));
    cin>>t;
    base.a[1][1]=1;
    base.a[3][1]=1;
    base.a[1][2]=1;
    base.a[2][3]=1;
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&k);
        sj ans; 
        memset(ans.a,0,sizeof(ans.a));
        ans=fastpo(base,k-1);
        cout<<ans.a[1][1]<<endl;
    }
}
