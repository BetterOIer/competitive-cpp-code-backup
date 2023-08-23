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
long long val[3005],wei[3005];
long long mv[3005],tmp[3005],idx=0;
bool vaild(long long x){
    long long cnt = 1;
    while(x){
        if(x&1){
            tmp[++idx] = cnt;
        }
        cnt++;
        x>>=1;
    }
    if(tmp[idx]-tmp[1]+1>idx){
        return true;
    }
    return false;
}
long long getwei(){
    long long ans=0;
    for(long long i = 1;i<=idx;i++){
        ans+=wei[tmp[i]];
    }
    return ans;
}
long long getval(){
    long long ans=0;
    for(long long i = 1;i<=idx;i++){
        ans+=val[tmp[i]];
    }
    return ans;
}
int main(){
    n=read(),m=read();
    for(long long i = 1;i<=n;i++){
        wei[i]=read(),val[i]=read();
    }
    long long tot = (1<<n)-1;
    for(long long i = 0;i<=m;i++){
        mv[i]=-1;
    }
    for(long long i= 1;i<=tot;i++){
        if(vaild(i)){
            long long we = getwei();
            mv[we] = max(mv[we],getval());
        }
        idx = 0;
    }
    for(long long i = 1;i<=m;i++){
        cout<<mv[i]<<" ";
    }
    return 0;
}