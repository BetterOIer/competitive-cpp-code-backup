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
inline unsigned long long read(){unsigned long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
unsigned long long dp[1000004],f[1000005];
unsigned long long table[10],k,l,r;
int main(){
    k=read(),l=read(),r=read();
    for(int i = 0;i<10;i++){
        table[i]=dp[i]=i*i*k;
        if(i)f[i]=f[i-1];
        if(dp[i]==i)++f[i];
    }
    for(int i = 10;i<=1000000;i++){
        dp[i]=dp[i/10]+table[i%10];
        f[i]=f[i-1];
        if(dp[i]==i)++f[i];
    }
    /* cout<<dp[9999]<<endl; */
    /* for(unsigned long long i = 0;i<=400;i++){
        cout<<i<<" "<<dp[i]<<" "<<f[i]<<endl;
        if(i%10==9)cout<<endl;
        if(i%100==99)cout<<"===\n";
    } */
    cout<<f[r]-f[l-1];
}

//TODO: 挑一个好区间