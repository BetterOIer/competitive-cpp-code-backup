#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
int k,n;
int poly[2005],ans[2005],tmp[2005];
void mul(int *f,int *g){
	memset(tmp,0,sizeof tmp);
	for(int i=0;i<=k;i++)for(int j=0;j<=k;j++){
		tmp[i+j]=(tmp[i+j]+1ll*f[i]*g[j])%mod;
	}
	for(int i=2*k;i>=k+1;i--){
		int got=tmp[i];
		tmp[i]=0;
		for(int j=i-1;j>=i-k;j--){
			tmp[j]=(tmp[j]+got)%mod;
		}
	}
}
int main(){
	cin>>k>>n;
	poly[1]=1;
	ans[0]=1;
	do{
		if(n&1){
			mul(ans,poly);
			memcpy(ans,tmp,sizeof ans);
		}
		mul(poly,poly);
		memcpy(poly,tmp,sizeof poly);
	}while(n>>=1);
	int fans=0;
	for(int i=1;i<=k;i++)fans=(fans+ans[i])%mod;
	cout<<fans<<endl;
	return 0;
}