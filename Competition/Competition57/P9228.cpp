/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,k,a[1000005],b[1000005],ans,cnt,can;
bool cmp(long long a,long long b){return a>b;}
int main(){
    n=read(),m=read(),k=read();
    for(long long i = 1;i<=n;i++) a[i]=read(),ans+=a[i];
    for(long long i = 1;i<=m;i++) b[i]=read(),ans+=b[i];
    sort(a+1,a+n+1,cmp);
    cnt=min(n,m);
    for(long long i = 1;i<=cnt;i++){
        if(a[i]>k){
            ans+=a[i],++can;
        }
    }
    cout<<ans+k*(cnt-can);
    return 0;
}
