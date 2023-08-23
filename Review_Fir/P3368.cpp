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
long long sum(long long pos){
    long long ans=0;
    for(;pos>0;pos-=lowbit(pos)){
        ans+=c[pos];
    }
    return ans;
}
int main(){
    n=read(),m=read();
    for(long long i = 1,now,last=0;i<=n;i++){
        now=read();
        add(i,now-last);
        last=now;
    }
    for(long long i = 1,opt,x,y,k;i<=m;i++){
        opt=read(),x=read();
        if(opt&1){
            y=read(),k=read();
            add(x,k);add(y+1,-k);
        }else{
            cout<<sum(x)<<endl;
        }
    }
    return 0;
}