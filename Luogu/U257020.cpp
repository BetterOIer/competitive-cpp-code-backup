#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int g[3005],f[3005],a;
const int mod = 998244353;
int main(){   
    int T=read();
    while(T--){
        //TODO clean
        int n=read();
        for(int i = 1;i<=n;i++){
            f[i]=g[i]=0;
        }
        f[0]=g[0]=1;
        for(int i = 1;i<=n;i++){
            a=read();
            if(a==0)continue;
            for(int j = n;j>=a;j--){
                f[j]|=f[j-a];
                g[j]=(g[j]+g[j-a])%mod;
            }
        }
        for(int i = n;~i;i--){
            if(f[i]){
                printf("%d %d\n",i,g[i]);
                break;
            }
        }
    } 
}
