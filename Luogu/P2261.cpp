#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,k;
int main(){
    n=read(),k=read();
    long long sum=n*k;
    for(long long l=1,r;l<=n;l=r+1){
		if(k/l==0)r=n;
        else r=min(n,k/(k/l));
        sum-=(k/l)*(r-l+1)*(l+r)/2;
	}
    cout<<sum;
}