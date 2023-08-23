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
int n;
long long xxj[62];
void insert(long long cnt){
    for(int i = 61;~i;i--){
        if(cnt&(1LL<<i)){
            if(!xxj[i]){xxj[i]=cnt;return;}
            else cnt^=xxj[i];
        }
    }
}
long long query(){
    long long ans=0;
    for(int i = 61;~i;i--){
        ans=max(ans,ans^xxj[i]);
    }
    return ans;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        long long cnt=read();
        insert(cnt);
    }
    cout<<query();
    return 0;
}
