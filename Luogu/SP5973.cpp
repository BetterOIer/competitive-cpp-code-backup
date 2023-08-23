#include<iostream>
using namespace std;
const int mod = 8388608;
int n,k,T,c[100010][25],power;
int main()
{
    scanf("%d",&T);
    c[0][0]=1;
    for(int i=1;i<=100000;i++){
        c[i][0]=1;
        for(int j=1;j<=23;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    while(T--)
    {
        scanf("%d%d",&n,&k);int ans=0,power=1;
        for(int i=1;i<=min(k,23);i++){
            ans=(ans+1ll*c[n][i]*i%mod*power%mod)%mod,power=1ll*power*2%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}