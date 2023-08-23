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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int big;
int a[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    n=read();
    big=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1,cmp);
    int cnt=1;
    while(big>0){
        big-=a[cnt++];
    }
    cout<<cnt-1;
    return 0;
}