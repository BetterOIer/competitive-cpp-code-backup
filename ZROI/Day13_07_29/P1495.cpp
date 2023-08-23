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
long long n,r[11],m[11],M=1;
void exgcd(long long a,long long b,long long &x,long long &y){
    if(!b){
        return x=1,y=0,void();
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
long long CRT(){
    long long ans=0;
    for(long long i = 1;i<=n;i++) M*=m[i];
    for(long long i = 1;i<=n;i++){
        long long c=M/m[i],x,y;
        exgcd(c,m[i],x,y);
        ans+=r[i]*c*x%M;
    }
    return (ans%M+M)%M;
}
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        m[i]=read(),r[i]=read();
    }
    cout<<CRT();
    return 0;
}