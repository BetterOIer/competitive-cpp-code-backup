/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[1005][1005];
int main(){
    int n=read();
    for(int i = 1;i<=n;i++) for(int j = i+1,t=1;j<=n;j++) a[i][j]=t,t=1-t;
    for(int i = 1;i<=n;i++) for(int j = i+1,t=0;j<=n;j++) a[j][i]=t,t=1-t;
    for(int i = 1;i<=n;i++){for(int j = 1;j<=n;j++)cout<<a[i][j];cout<<"\n";}
    return 0;
}