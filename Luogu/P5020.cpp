#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[1000005],maxn = 0;
int f[1000005];
int main(){
    int T=read();
    while(T--){
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        maxn=0;
        int n=read();
        for(int i = 1;i<=n;i++){
            a[i]=read();
            maxn = max(a[i],maxn);
        }
        f[0]=1;
        sort(a+1,a+n+1);
        int ans=n;
        for(int i = 1;i<=n;i++){
            if(f[a[i]])ans--;
            else{
                for(int j = a[i];j<=maxn;j++)f[j]|=f[j-a[i]];
            }
        }
        cout<<ans<<endl;
    }
}