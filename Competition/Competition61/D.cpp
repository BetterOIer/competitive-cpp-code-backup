/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: http://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int p[1000005];
int main(){
    /* freopen("ex_perm2.in","r",stdin);
    freopen("ex_perm2.outt","w",stdout); */
    n=read();
    for(int i = 1;i<=n;i++){
        p[i]=read();
    }
    long long ans=0;
    for(int i = 1;i<=n-3;i++){
        for(int j = i+1;j<=n-2;j++){
            for(int k = j+1;k<=n-1;k++){
                for(int l = k+1;l<=n;l++){
                    if(p[i]<p[k]&&p[k]<p[j]&&p[j]<p[l])ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}