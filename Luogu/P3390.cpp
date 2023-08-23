#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
int n;
struct Matrix{
    LL a[105][105];
    Matrix operator * (const Matrix &x)const
    {
        Matrix ans;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                ans.a[i][j]=0;
                for (int k=1;k<=n;k++)
                    ans.a[i][j]=(ans.a[i][j]+a[i][k]*x.a[k][j])%mod;
            }
        return ans;
    }
}x,ans;
int main()
{
    LL k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        cin>>x.a[i][j];
    ans=x,k--;
    while (k)
    {
        while ((k&1LL)==0) x=x*x,k>>=1LL;
        ans=ans*x;
        k>>=1LL,x=x*x; 
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout<<ans.a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
