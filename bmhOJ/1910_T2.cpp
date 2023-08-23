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
const long long p = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
char c[1000005];
long long t1[1000005],sum[1000005],f[1000005],g[1000005],t2[1000005],po[1000005];
int main(){
    long long n=read(),k=read();
	scanf("%s",c+1);
	po[0]=1;
	long long s=0; 
	for(long long i=1;i<=n;i++){
		if(c[i]=='W') s=0;
		else s++;
		if(s>=k)f[i]=((po[i-k]-t1[i-k]+p)%p-(sum[i-1]-sum[i-k]+p)%p+p)%p;
		if(c[i]=='X') po[i]=(po[i-1]*2)%p;
		else po[i]=po[i-1];
		if(c[i]=='X') t1[i]=(t1[i-1]*2+f[i])%p;
		else t1[i]=(t1[i-1]+f[i])%p;
		sum[i]=(sum[i-1]+f[i])%p;
	}
	po[n+1]=1;s=0;
	for(long long i=n;i>=1;i--){
		if(c[i]=='B') s=0;
		else s++;
		if(s>=k)g[i]=((po[i+k]-t2[i+k]+p)%p-(sum[i+1]-sum[i+k]+p)%p+p)%p;
		if(c[i]=='X') po[i]=(po[i+1]*2)%p;
		else po[i]=po[i+1];
		if(c[i]=='X') t2[i]=(t2[i+1]*2+g[i])%p;
		else t2[i]=(t2[i+1]+g[i])%p;
		sum[i]=(sum[i+1]+g[i])%p;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++) ans=(ans+f[i]*t2[i+1])%p;
	cout<<ans;
    return 0;
}