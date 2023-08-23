#include<iostream>
using namespace std;
const int mod = 19260817;
long long x,y;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=((x<<3)+(x<<1)+(c^48))%mod;
	return x*f;
}
void exgcd(long long a,long long b){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b);
    long long z=x;
    x=y;
    y=z-a/b*y;
}
int main(){
    long long a=read(),b=read();
    if(b==0){
        cout<<"Angry!";
        return 0;
    }
    exgcd(b,mod);
    x=(x%mod+mod)%mod;
    cout<<(long long)(x)*a%mod;
}