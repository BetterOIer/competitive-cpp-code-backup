#include <iostream>
using namespace std;
long long n,ans;
long long inv(long long x){
	if (x==1) return 1;
	return (998244353-998244353/x)*inv(998244353%x)%998244353;
}
int main(){
	scanf("%lld",&n);n%=998244353;
	if (!n) ans=inv(2);
	else ans=inv(2)*(1-3*inv(n)%998244353*inv(n+2)%998244353+998244353)%998244353;
    cout<<ans;
}