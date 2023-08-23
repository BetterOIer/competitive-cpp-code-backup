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
long long l,r,ans;
bool vis[5000005]={1,1},viss[1000005];
long long pri[5000005],tot;
void ols(){
    for(long long i = 2;i<=5000005;i++){
        if(!vis[i])pri[++tot]=i;
        for(long long j = 1;j<=tot&&i*pri[j]<=5000005;j++){
            vis[i*pri[j]]=true;
            if(i%pri[j]==0)break;
        }
    }
}
int main(){
    l=read(),r=read(),ols(),l=l==1?2:l;
    for(long long i=1;i<=tot;++i){
        long long sta=(l+pri[i]-1)/pri[i]*pri[i]==pri[i]?2*pri[i]:(l+pri[i]-1)/pri[i]*pri[i];
        //cout<<"sta: "<<sta<<endl;
        for(long long j=sta;j<=r;j+=pri[i])viss[j-l+1]=1;
    }
    for(long long i=1;i<=r-l+1;++i)if(!viss[i])ans++;
    cout<<ans;
    return 0;
}