#include<iostream>
using namespace std;
const long long mod = 998244353;
long long qpow(long long x, long long y) {
	long long r = 1;
	while (y > 0) {
		if (y & 1) 
			r = r * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return r;
}
int main(){
    long long T;
    cin>>T;
    while(T--){
        long long n,ans2=0;
        cin>>n;
        for(long long i = 1,j;i<=n;i++){
            cin>>j;
            ans2|=j;
        }
        long long ans=(qpow(2,n-1)*ans2)%mod;
        cout<<ans<<endl;
    }
}