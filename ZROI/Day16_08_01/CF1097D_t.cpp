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
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    long long d=exgcd(b, a%b, y, x);
    y-=a/b*x;
    return d;
}
long long inv(long long a,long long b){ //表示求a在模b意义下的逆元
    long long x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
int main(){
    cout<<0;
    for(long long i = 1;i<=65;i++){
        cout<<", "<<inv(i,1000000005);
    }
    return 0;
}