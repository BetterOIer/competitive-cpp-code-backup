#include<iostream>
using namespace std;
const long long mod=998244353;
long long exgcd(long long a,long long b,long long &x,long long &y){
    long long ret,tmp; 
    if (!b){
        x=1;
        y=0;
        return a;
    } 
    ret=exgcd(b,a % b,x,y); 
    tmp=x;
    x=y; 
    y=tmp-a / b * y;
    return ret; 
} 
long long inv(long long a,long long b){
    long long x,y;
    exgcd(a,b,x,y);
    return x;
}
string s1,s2;
int main(){
	cin >> s1>> s2;
	long long n =0,m=0;
	for(long long i=0;i<s1.size();++i)
		n=(n*10+s1.at(i)-'0')%mod;
	for(long long i=0;i<s2.size();++i)
		m=(m*10+s2.at(i)-'0')%mod;
	cout<<((1-1ll*m*inv(1ll*n*n%mod,mod))%mod+mod)%mod<<endl;
	return 0;
}