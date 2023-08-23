#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int M=11;
int n,m,x,maxn,minn=2147483647,a[N+N],f[N][M],g[N][M],sum[N][N];
void dp(int *a){
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            sum[i][j]=(sum[i][j-1]+a[j])%10;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            g[i][j]=2147483647;
            f[i][j]=0;
        }
    f[0][0]=g[0][0]=1;
    for(int j=1;j<=m;j++)
        for(int i=j;i<=n;i++)
            for(int l=0;l<i;l++){
                f[i][j]=max(f[i][j],f[l][j-1]*sum[l+1][i]);
                if(g[l][j-1]!=2147483647) g[i][j]=min(g[i][j],g[l][j-1]*sum[l+1][i]);
            }
    maxn=(maxn>f[n][m]? maxn:f[n][m]);
    minn=(minn<g[n][m]? minn:g[n][m]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=abs(x)%10;
        if(x<0)a[i]=10-a[i];
        a[i+n]=a[i];
    }
    for(int i=0;i<n;i++)dp(a+i);
    cout<<minn<<endl<<maxn<<endl;
    return 0;
}
