#include<iostream>
#include<algorithm>
using namespace std;
long long n,k;
long long a[1000005];
bool DIVID(long long x) {
	long long ans = 0;
	for (int i=1;i<=n;i++) {
		ans += a[i]/x;
	}
	return ans>= k;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	long long l=0,r=100000001;
	long long mid;
	while (l+1<r) {
		mid = (l + r)/2;
		if(DIVID(mid)) l = mid;
		else r = mid;
	}
	cout<<l<<endl;
	return 0;
} 
