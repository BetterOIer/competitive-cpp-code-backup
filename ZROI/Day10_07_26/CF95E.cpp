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
const long long table[62]={4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477, 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747, 77774, 77777};
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,fa[1000005], size[1000005], dp[1000005],tmp[1000005], ans=12345678987654321;
long long find(long long pos){if(pos==fa[pos])return pos;return fa[pos] = find(fa[pos]);}
int main(){
    n=read(),m=read();
    for(long long i = 1;i<=n;i++) fa[i]=i;
    for(long long i = 1,x,y;i<=m;i++) x=read(),y=read(),fa[find(x)]=find(y);
    for(long long i = 1;i<=n;i++) size[find(i)]++;    
    for(long long i = 1;i<=n;i++) tmp[size[i]]++;
    for(long long i = 1;i<=n;i++) dp[i]=12345678987654321;
    for(long long i = 1;i<=n;i++){
        if(!tmp[i])continue;
        long long cnt=tmp[i];
        for(long long j = 1,w;cnt;j<<=1){
            j=min(j,cnt),cnt-=j,w=j*i;
            for(long long o = n;o>=w;o--) dp[o]=min(dp[o],dp[o-w]+j);
        }
    }
    for(long long i = 0;i<62&&table[i]<=n;i++) ans=min(ans,dp[table[i]]);
    if(ans==12345678987654321) ans=-1;
    else ans--;
    cout<<ans;
    return 0;
}