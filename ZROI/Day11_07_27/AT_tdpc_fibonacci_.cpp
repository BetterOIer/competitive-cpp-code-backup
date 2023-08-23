/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
const int mod=1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k,fans;
int poly[2005],ans[2005],tmp[2005];
void mul(int *f, int *g){
    for(int i = 0;i<=2000;i++)tmp[i]=0;
    for(int i = 0;i<=k;i++)for(int j = 0;j<=k;j++) tmp[i+j]=(tmp[i+j]+1ll*f[i]*g[j])%mod;
    for(int i = (k<<1);i>=k+1;i--){
        int got = tmp[i];tmp[i]=0;
        for(int j = i-1;j>=i-k;j--) tmp[j]=(tmp[j]+got)%mod;
    }
}
int main(){
    k=read(),n=read(),poly[1]=ans[0]=1;
    do{
        if(n&1) mul(ans,poly),memcpy(ans,tmp,sizeof ans);
        mul(poly,poly); memcpy(poly,tmp,sizeof poly);
    }while(n>>=1);
    for(int i = 1;i<=k;i++)(fans+=ans[i])%=mod;
    cout<<fans<<endl;
    return 0;
}