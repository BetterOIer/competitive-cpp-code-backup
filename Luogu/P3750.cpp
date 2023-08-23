/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
君埋泉下泥销骨，我寄人间雪满头。 --梦微之
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int mod = 100003;
int n,k;
int a[100010];
int cnt=0;
long long f[100010];
long long quick_pow(long long a,long long b){long long res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
int main(){
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=n;i>=1;i--){
        if(a[i]){
            cnt++;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    a[j]^=1;
                    if(j*j!=i)  a[i/j]^=1;
                }
            }
        }
    }
    f[n+1]=0;
    for(int i=n;i>=1;i--){
        long long temp=(long long)(n-i)*f[i+1]%mod;
        temp=(temp+(long long)n)%mod;
        temp=temp*quick_pow(i,mod-2)%mod;
        f[i]=temp;
    }
    long long temp=0;
    if(cnt<=k)temp=cnt;
    else{
        for(int i=cnt;i>k;i--)  temp=(temp+f[i])%mod;
        temp=(temp+k)%mod;
    }
    for(int i=1;i<=n;i++)temp=(temp*(long long)i)%mod;
    printf("%lld\n",temp);
    return 0;
}