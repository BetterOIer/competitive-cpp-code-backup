#include<iostream>
using namespace std;
const int mod=1e9+7;
long long a[100005],n,ans=1,minn=9223372036854775807ll;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	for(int i=1;i<=n;i++) ans=((a[i]/minn)%mod*(ans%mod))%mod;
	cout<<minn<<" "<<ans;
	return 0;
}