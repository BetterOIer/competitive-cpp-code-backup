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
int n,legal=0,idx,nowl,nowr,tmpl,tmpr;
int a[6000005];
bool pla[6000005];
int solve(int x){
    int ans=0;
    while(tmpr-tmpl+1>x||tmpr<n){
        ans++;
        pla[++idx]=1;
        tmpr=idx;tmpl++;
        while(!pla[tmpl])tmpl++;
    }
    return ans;
}
int main(){
    freopen("change.in","r",stdin);
    freopen("change.out","w",stdout);
    n=read();
    nowl=n,nowr=1;
    for(int i = 1;i<=n;i++){
        idx=n;
        a[i]=read();
        pla[a[i]]=1;
        if(a[i]>nowr)nowr=a[i];
        if(a[i]<nowl)nowl=a[i];
        tmpl=nowl,tmpr=nowr;
        int ans=solve(i);
        cout<<ans<<" ";
    }
    return 0;
}