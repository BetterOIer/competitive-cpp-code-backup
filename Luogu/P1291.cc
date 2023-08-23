#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n,sum=1,p;
long long gcd(long long m, long long n){
    while (n != 0){
        long long t = m % n;
        m = n;
        n = t;
    }
    return m;
}
int main(){
	n=read();
	p=n;
	for(long long i=2;i<=n;i++){
		long long fm=sum*i;
		long long fz1=p*i,fz2=n*sum;
		long long fz=fz1+fz2;
		long long k=gcd(fz,fm);
		fz/=k;fm/=k;
		sum=fm;
		p=fz;
	}
	if(p%sum==0) cout<<p/sum;
	else{
		long long num=0,k=p/sum,o=p,num1=0,u=sum;
		while(k>0){
			num++;
			k/=10;
		}
		while(u>0){
			num1++;
			u/=10;
		}
		for(long long i=1;i<=num;i++) cout<<' ';
		cout<<o%sum<<endl<<o/sum;
		for(long long i=1;i<=num1;i++) cout<<'-';
		cout<<endl;
		for(long long i=1;i<=num;i++) cout<<' ';
		cout<<sum<<endl;
	}
	return 0;
}
