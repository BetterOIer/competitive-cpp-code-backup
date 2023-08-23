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
int h[1005],n;
float ans=0;
int main(){
    n=read();
    for(int i = 1;i<=n;i++) h[read()]++;
    for(int i = 1,sum=0;i<=1000;i++) ans+=1.0*h[i]*(n+1)/(n-sum+1),sum+=h[i];
    printf("%.2f",ans);
    return 0;
}