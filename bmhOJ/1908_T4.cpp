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
int n,m;
long long a[100005],dp[100005][2],q[100005],p[100005],h1,t1,h2,t2;
void dpm(int i){while(h1<=t1&&dp[q[t1]+1][1]+a[q[t1]]<=dp[i+1][1]+a[i])t1--;}
void dpn(int i){while(h2<=t2&&dp[p[t2]+1][0]-a[p[t2]]>=dp[i+1][0]-a[i])t2--;}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    q[h1=t1=0]=n;
	p[h2=t2=0]=n;
    for(register int i=n;i>=1;i--){
        dpm(i);q[++t1]=i;
        dpn(i);p[++t2]=i;
        while(h1<=t1&&q[h1]>=i+m)h1++;
        dp[i][0]=a[q[h1]]+dp[q[h1]+1][1];
        while(h2<=t2&&p[h2]>=i+m)h2++;
        dp[i][1]=dp[p[h2]+1][0]-a[p[h2]];
    }
    cout<<dp[1][0]<<endl<<dp[1][1];
    return 0;
}