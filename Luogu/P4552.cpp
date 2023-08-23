#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn = 1000005;
long long a[maxn],cf[maxn];
long long down,up;
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=n;i++){
        cf[i]=a[i]-a[i-1];
        if(i==1)continue;
        if(cf[i]<0)down+=(-cf[i]);
        else if(cf[i]>0)up+=cf[i];
    }
    cout<<max(down,up)<<endl<<abs(down-up)+1;
}