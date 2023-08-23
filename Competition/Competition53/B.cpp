#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long a[100005];
const int mod = 1e9+7;
void init(){
    a[1]=1;
    for(int i = 2;i<=10000;i++){
        a[i]=a[i-1]*i%mod;
    }
}
int main(){
    init();
    int t=read();
    while(t--){
        int n=read();
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        long long ans=1;
        ans=ans*a[n]%mod;
        ans=ans*n%mod;
        ans=ans%(n-1)%mod;
        cout<<ans<<endl;
    }
    return 0;
}