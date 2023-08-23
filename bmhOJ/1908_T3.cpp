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
int n,scr[3000006],mx[3000006];
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        scr[i]=read();
    }
    sort(scr+1,scr+n+1);
    mx[n]=scr[n]+1;
    for(int i = n-1;i>=1;i--){
        mx[i]=max(mx[i+1],scr[i]+n+1-i);
    }
    int ans=1;
    for (int i=n-1;i>=1;i--) if (scr[i]+n>=mx[i+1]) ans++;
    cout<<ans;
    return 0;
}