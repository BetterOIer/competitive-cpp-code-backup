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
int a[5005],ans=2147483647,cou=0;
void dfs(int pos,int cho, int lei,int maxn){
    if(cho>m)return;
    if(pos == n+1){
        if(ans>maxn){
            ans=maxn;
            cou=1;
        }else if (ans==maxn){
            cou+=1;
        }
        return ;
    }
    if(pos!=n)dfs(pos+1,cho+1,0,max(maxn,lei+a[pos]));
    dfs(pos+1,cho,lei+a[pos],max(maxn,lei+a[pos]));
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    dfs(1,0,0,0);
    cout<<ans<<" "<<cou<<endl;
    return 0;
}