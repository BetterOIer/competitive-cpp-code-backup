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
int pri[50005],mu[50005],sum[50005],tot;
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
int cal(int a,int b,int k){
    if(a<b)swap(a,b);
    int r,res=0;
    for(int l = 1;l<=b;l=r+1){
        r=min(a/(a/l),b/(b/l));
        res+=(sum[r]-sum[l-1])*(a/(l*k))*(b/(l*k));
    }
    return res;
}
int main(){
    get_mu(50000);
    int n=read();
    while(n--){
        int c=read(),a=read(),k=read(),b=read(),d=read();
        cout<<cal(a,b,d)-cal(a,k-1,d)-cal(c-1,b,d)+cal(c-1,k-1,d)<<endl;
    }
    return 0;
}