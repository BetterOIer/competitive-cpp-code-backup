#include<iostream>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,k;
int p[4003],w[25][4003];
ll f[4003][4003],ans;
int main(){
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        p[i]=read();
        for(int j=1;j<=p[i];j++){`
            w[j][i]=read();
        }
    }
    for(int W=1;W<=n;W++){
        for(int i=1;i<=n;i++){
            if(i==W)continue;
            for(int j=k;j>=p[i];--j){
                f[W][j]=max(f[W][j],f[W][j-p[i]]+w[p[i]][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=k-1;j+p[i]>k;--j){
            ans=max(f[i][j]+w[k-j][i],ans);
        }
    }
    cout<<ans;
}