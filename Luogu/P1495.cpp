#include<iostream>
using namespace std;
long long n,Mi[18],a[18],m[18],mul=1,x,y,ans=0;
long long ex_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	long long nowx=ex_gcd(b,a%b,y,x);;
	y-=a/b*x;
	return nowx;
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>m[i];
        mul*=a[i];
    }
    for(int i = 1;i<=n;i++) Mi[i]=mul/a[i];
    for(int i = 1;i<=n;i++){
        Mi[i]=mul/a[i];
        x=y=0;
        long long cnt=ex_gcd(Mi[i],a[i],x,y);
        x/=cnt;
        ans+=m[i]*Mi[i]*x;
    }
    cout<<(ans%mul+mul)%mul;
}