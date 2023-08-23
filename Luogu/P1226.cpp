#include<iostream>
using namespace std;
long long a,b,q;
long long mod(long long x,long long y){
	if(y==1)return x;
	long long w=mod(x,y/2)%q;
	if(y%2==0) return (w*w)%q;
	else return ((w*w)%q*x%q)%q;
}
int main(){
	cin>>a>>b>>q;
	long long r=mod(a,b);
	cout<<a<<"^"<<b<<" mod "<<q<<"="<<r;
}