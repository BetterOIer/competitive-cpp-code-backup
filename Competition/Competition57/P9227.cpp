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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long a[10005],n,k;
int main(){
    long long t=read();
    while(t--){
        n=read(),k=read();
        long long all=0;
        for(long long i = 1;i<=n;i++){
            a[i]=read();
            all^=a[i];
        }
        if(k%2==1||n%2==1){
            for(long long i = 1;i<=n;i++){
                a[i]=(all^a[i]);
            }
        }
        for(long long i =1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        puts("");
    }
    return 0;
}