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
long long n,m;
long long a[1000005];
long long xos[1000005];
long long table[62]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,2251799813685248,4503599627370496,9007199254740992,18014398509481984,36028797018963968,72057594037927936,144115188075855872,288230376151711744,576460752303423488,1152921504606846976,2305843009213693952,4611686018427387904};
int main(){
    freopen("1.in","r",stdin);
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=i;xos[i]=xos[i-1]^a[i];
    }
    for(long long i = 1+n;i<=m+n;i++){a[i]=read();xos[i]=xos[i-1]^a[i];}
    int ans=0;
    cout<<xos[m+n]<<endl;
    for(long long j = 1;j<=n+m;j++){
        long long cnt=xos[m+n]^a[j];
        if(cnt<a[j])ans+=1;
    }
    cout<<ans;
    return 0;
}