//!我真的不会写QaQ
/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,a,b;
int f[2005],g[2005],h[2005],dp[2005][2005];
void update(int &x,const int &y){if(y>x)x=y;}
int main(){
    n=read(),a=read(),b=read();
    for(int i = 1,z,x;i<=n;i++){
        scanf("%d.%d",&z,&x);
        f[i]=z*1000+x;
    }
    for(int i = 1,z,x;i<=n;i++){
        scanf("%d.%d",&z,&x);
        g[i]=z*1000+x;
        h[i]=1e6-(1e3-f[i])*(1e3-g[i]);
        f[i]*=1000,g[i]*=1000;
    }
    for(int i = 1;i<=n;i++){
        for(int x = min(i,a);x>a-(n-i)-2&&x>0;x--){
            for(int y = min(i,b);y>b-(n-i)-2&&y>0;y--){
                update(dp[x][y],dp[x-1][y-1]+h[i]);
                update(dp[x][y],dp[x-1][y]+f[i]);
                update(dp[x][y],dp[x][y-1]+g[i]);
            }
        }
        for(int x = min(i,a);x>0;x--)update(dp[x][0],dp[x-1][0]+f[i]);
        for(int y = min(i,b);y>0;y--)update(dp[0][y],dp[0][y-1]+g[i]);
    }
    printf("%.2lf\n",1.0*dp[a][b]/1e6);
    return 0;
}