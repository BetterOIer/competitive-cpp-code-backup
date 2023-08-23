#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
};
inline void write(__int128 x)
{
	if (!x) return ;
	if (x < 0) putchar('-'),x = -x;
	write(x / 10);
	putchar(x % 10 + '0');
}
__int128 a,b,c,ans=0;

int main(){
	long long n=read(),k=read();
	long long cal=n/k;
	long long most=cal+1;
	long long left=n%k;
	for(long long i = 3;i<=cal;i++){
		a=a+i-2;
		b=b+a;
	}
	a=a+most-2;
	c=b+a;
	ans+=(k-left)*b;
	ans+=c*left;
	write(ans);
	return 0;
}
