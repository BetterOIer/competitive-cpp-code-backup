#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long cir[1000005],n;
long long lim=-9223372036854775807ll - 1;
int main(){
    freopen("dungeon.in","r",stdin);
    freopen("dungeon.out","w",stdout);
    long long T=read();
    while(T--){
        long long n=read(),p1,p2;
        p1=n,p2=n+2;
        for(long long i = 1;i<=n;i++){
            cir[i]=cir[i+n]=read();
        }
        long long now=cir[1+n];
        lim=-9223372036854775807ll - 1;
        lim=max(lim,-now);
        while(p2-p1<=n){
            if(cir[p1]>cir[p2]) now+=cir[p1--];
            else now+=cir[p2++];
            lim=max(lim,-now);
        }
        cout<<max(lim,0LL)<<endl;
    }
    return 0;
}