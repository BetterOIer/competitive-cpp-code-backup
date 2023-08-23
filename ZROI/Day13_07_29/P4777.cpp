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
inline __int128 read(){
    __int128 x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
__int128 n;
__int128 m[100008],r[100008];
__int128 exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y){
    if(!b)return x=1,y=0,a;
    __int128 d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
__int128 mul(__int128 a,__int128 b,__int128 mod)
{
    __int128 c=a*b-(__int128)((long double)a*b/mod+0.5)*mod;
    return c<0?c+mod:c;
}
__int128 exCRT(){
    for(__int128 i = 2,x,y;i<=n;i++){
        __int128 d=exgcd(m[i-1],m[i],x,y);
        if((r[i]-r[i-1])%d!=0)return -1;
        x=mul(x,((r[i]-r[i-1])/d),(m[i]/d));
        x=(x%(m[i]/d)+m[i]/d)%(m[i]/d);
        r[i]=m[i-1]*x+r[i-1];
        m[i]=m[i-1]*m[i]/d;
    }
    return (r[n]%m[n]+m[n])%m[n];
}
int main(){
    n=read();
    for(__int128 i = 1;i<=n;i++){
        m[i]=read(),r[i]=read();
    }
    __int128 ans=exCRT();
    if(ans==-1) cout<<"No Answer"<<endl;
    else cout<<(long long)ans;
    return 0;
}