#include<iostream>
using namespace std;
int n,k,f[2000005],a[1000005],ans=0;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void cal(int num){
    int fpo=0;
    for(int i = 20;i>=0;i--){
        if(((k>>i)&1)&&((num>>i) & 1)) f[fpo+(1<<i)]++,f[fpo+(1<<(i+1))]--;
        else if((k>>i)&1) f[fpo]++,f[fpo+(1<<i)]--,fpo+=(1<<i);
        else if((num>>i) & 1) fpo+=(1<<i);
    }
}
int main(){
    n=read(),k=read();
    for(int i = 1;i<=n;i++) a[i]=read(),cal(a[i]);
    for(int i = 0;i<=(1<<20);i++)if(i) f[i]+=f[i-1],ans=max(ans,f[i]);
    cout<<ans<<endl;
}