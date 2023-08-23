//*** Le vent se lève, il faut tenter de vivre !***
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int aer[200005],a[200005],b[200005],k[200005],cnt=0;
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i = 1;i<=n;i++)a[i]=read();
        for(int i = 1;i<=n;i++)b[i]=read();
        for(int i = 1;i<=n;i++) if(a[i] > b[i]) aer[b[i]]++,aer[a[i]]--;
        for(int i = 1;i<=n;i++)aer[i]=aer[i-1]+aer[i];
        for(int i = 1;i<=n;i++){
            bool ok = 1;
            for(int j = i;j<=n;j+=i) ok&=!aer[j];
            if(ok) k[++cnt]=i;
        }
        cout<<cnt<<endl;
        for(int i = 1;i<=cnt;i++) cout<<k[i]<<" ";
        cout<<endl;
        for(int i = 0;i<=n+1;i++)aer[i]=0;
        cnt=0;
    }
}