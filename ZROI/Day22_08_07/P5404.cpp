#include<iostream>
#include<cstring>
using namespace std;
const int mod=998244353;
char s[2005];
int n,m,nex[2005];
long long ans,f[2005]={1};
inline int qpow(long long a,long long b){long long res=1;while(b){if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;b>>=1;}return res;}
int main(){
	scanf("%d%s",&m,s+1),n=strlen(s+1);
	for(int i = 2;i<=n;i++){
		int j=nex[i-1];
		while(j && s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) nex[i]=j+1;
	}
	for(int i = 2;i<=n;i++) if(s[nex[i-1]+1]>s[i]){n=i-1; break;}
	while(nex[n]) n-=nex[n];
	if(n>m) n=m;
	else --s[n];
	for(int i = 1;i<=m;i++) for(int j = 1;j<=min(i,n);j++) f[i]=(f[i]+f[i-j]*('z'-s[j]))%mod;
	ans=f[m];
	for(int i = 2;i<=n;i++) ans=(ans+f[m-i]*('z'-s[i])*(i-1))%mod;
	ans=(qpow(26,m)-ans+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}