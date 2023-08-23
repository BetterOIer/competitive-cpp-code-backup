#include<iostream>
using namespace std;
const int mod=998244353;
long long power(long long a,long long n){
	long long mul=1;
	while(n){
		if(n%2) mul=(mul*a)%mod;
		a=a*a%mod;
		n/=2;
	}
	return mul;
}
int main(){
	long long n=0,m=0;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();++i)
		n=(n*10+s1.at(i)-'0')%mod;
	for(int i=0;i<s2.size();++i)
		m=(m*10+s2.at(i)-'0')%mod;
	cout<<power(n*n,mod-2)%mod*(n*n%mod-m)%mod<<endl;
	return 0;
}