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
bool dfs(int n,int m){
    if(n==m)return 1;
    if(m/n>=2)return 1;
    return dfs(m-n,n)^1;
}
int main(){
    int n,m;
    while(true){
        n=read(),m=read();
        if(!n&&!m)break;
        if(n>m)m^=n^=m^=n;
        if(dfs(n,m))cout<<"Stan wins\n";
        else cout<<"Ollie wins\n";
    }
    return 0;
}