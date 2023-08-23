#include<iostream>
using namespace std;
void read(long long &num){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	num=x*f;
}
long long n;
long long m;
long long face[2000005],C[2000005];
long long all=0;
long long dp[2000005]={1};
long long ans;
int main(){
	read(n),read(m);
	for(long long i = 1;i<=n;i++){
		read(face[i]);
	}
	for(long long i = 1;i<=n;i++){
		read(C[i]);
		all+=C[i]*face[i];
	}
	for(long long i = 1;i<=n;i++){
		for(long long j = all;j>=0;j--){
			for(long long w = 0;w<=face[i]&&w*C[i]<=j;w++){
				dp[j]=max(dp[j],dp[j-w*C[i]]*w);
			}
		}
	}
	while(ans<=all&&dp[ans]<m)ans++;
	cout<<ans<<endl;
}