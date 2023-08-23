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
int pri[50005],mu[50005],sum[50005],tot,ans;
bool vis[50005];
void get_mu(int n){
    mu[1]=1;
    for(int i = 2;i<=n;i++){
        if(!vis[i]){
            pri[++tot]=i;
            mu[i]=-1;
        }
        for(int j = 1;i*pri[j]<=n&&j<=tot;j++){
            int m=i*pri[j];
            vis[m]=1;
            if(i%pri[j]==0){
                mu[m]=0;
                break;
            }
            mu[m]=-mu[i];
        }
    }
    for(int i = 1;i<=n;i++){
        sum[i]=sum[i-1]+mu[i];
    }
}
int main(){
    get_mu(50000);
    int n=read();
    while(n--){
        int a=read(),b=read(),d=read();
        int r,A=a/d,B=b/d;
        if(A<B)swap(A,B);
        for(int l = 1;l<=B;l=r+1){
            r=min(A/(A/l),B/(B/l));
            ans+=(sum[r]-sum[l-1])*(A/l)*(B/l);
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}