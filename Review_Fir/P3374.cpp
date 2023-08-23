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
long long n,m;
long long c[5000005];
long long lowbit(long long x){return x&-x;}
void add(long long pos,long long num){
    for(;pos<=n;pos+=lowbit(pos)){
        c[pos]+=num;
    }
}
long long sum(long long r){
    long long ans=0;
    for(;r>0;r-=lowbit(r)){
        ans+=c[r];
    }
    return ans;
}
long long ask(long long l,long long r){
    return sum(r)-sum(l-1);
}
int main(){
    n=read(),m=read();
    for(long long i = 1,num;i<=n;i++){
        num=read();
        add(i,num);
    }
    for(long long i = 1,x,y,z;i<=m;i++){
        x=read(),y=read(),z=read();
        if(x==1)add(y,z);
        else cout<<ask(y,z)<<endl;
    }
    return 0;
}