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
int a[1000005],n;
int main(){
    n=read();
    if(n&1){
        for(int i = 0,x;i<n;i++){
            x=read();
            if(x&1)a[i]=(x+n)/2;
            else a[i]=x/2;
        }
        for(int i = 0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
        for(int i = 0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
    }else cout<<-1<<endl;
    return 0;
}