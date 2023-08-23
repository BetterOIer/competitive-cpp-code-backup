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
struct node{
    long long idx;
    long long a,b;
}s[1000005];
bool cmp(node a,node b){
    if(a.a==b.a)return a.b <b.b;
    return a.a<b.a;
}
void solve(long long num,long long gc){
    s[gc].idx=gc;
    s[gc].a=num;
    s[gc].b=num*gc;
}
int main(){
    n=read(),m=read();
    for(long long i = 1,num;i<=n;i++){
        num=read();
        solve(num,i);
    }
    sort(s+1,s+n+1,cmp);
    for(long long i = 1;i<=n;i++){
        cout<<s[i].idx<<" ";
    }
    return 0;
}