#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int x,y,n;
int gcd(int a,int b){
    return b==0? a:gcd(b,a%b);
} 
int main(){
    n=read();x=abs(read());
    for(int i = 1;i<n;i++){
        y=read();x=gcd(x,abs(y));
    }
    cout<<x;
    return 0;
}