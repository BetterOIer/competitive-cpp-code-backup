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
int dp[1000004],f[1000005];
int table[10];
int main(){
    for(int k = 1,cnt;k<=100;k++){
        for(int i = 1;i<10;i++){
            table[i]=dp[i]=i*i*k;
            if(i)f[i]=f[i-1];
            if(dp[i]==i){cnt=i;goto en;}
        }
        for(int i = 10;i<=1000000;i++){
            dp[i]=dp[i/10]+table[i%10];
            f[i]=f[i-1];
            if(dp[i]==i){cnt=i;goto en;}
        }
        en:
        cout<<k<<" "<<cnt<<" "<<cnt/k<<endl;
        /* cout<<dp[9999]<<endl; */
        /* for(int i = 0;i<=400;i++){
            cout<<i<<" "<<dp[i]<<" "<<f[i]<<endl;
            if(i%10==9)cout<<endl;
            if(i%100==99)cout<<"===\n";
        } */
    }
}