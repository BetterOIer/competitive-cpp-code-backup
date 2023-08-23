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
struct node{
    int ori;
    int abs;
}a[500005];
bool operator < (node a,node b){
    return a.abs>b.abs;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){a[i].ori=read();a[i].abs=abs(a[i].ori);}
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        cout<<a[i].ori<<" ";
    }
    return 0;
}