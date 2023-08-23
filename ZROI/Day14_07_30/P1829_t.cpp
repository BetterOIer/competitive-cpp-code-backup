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
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b, a%b, y, x);
    y-=a/b*x;
    return d;
}
int inv(int a,int b){ //表示求a在模b意义下的逆元
    int x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
int main(){
    cout<<inv(4,20101009);
    return 0;
}