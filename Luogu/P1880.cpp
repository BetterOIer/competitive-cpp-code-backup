#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dp1[15][15],dp2[15][15],sum[300],a[15];
int main(){
    int n=read();
    memset(dp1,0x3f3f3f,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    for(int i =1;i<=n;i++) a[i]=read(),dp1[i][i]=dp1[i+n][i+n]=dp2[i][i]=dp2[i+n][i+n]=0;
    for(int i = 1;i<=(n<<1);i++)sum[i]=sum[i-1]+a[(i-1)%n+1];
    for(int i = 2;i<=n;i++){
        for(int l = 1;l<=n+n-i+1;l++){
            int r=l+i-1;
            for(int k =l;k<r;k++){
                dp1[l][r]=min(dp1[l][r],dp1[l][k]+dp1[k+1][r]);
                dp2[l][r]=max(dp2[l][r],dp2[l][k]+dp2[k+1][r]);
            }
            dp1[l][r]+=sum[r]-sum[l-1];
            dp2[l][r]+=sum[r]-sum[l-1];
        }
    }
    int ans1=0x3f3f3f,ans2=0;
    for(int i = 1;i<=(n<<1);i++){
        ans1=min(ans1,dp1[i][i+n-1]);
        ans2=max(ans2,dp2[i][i+n-1]);
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}