#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int phi[400004];
bool vis[400004];
int cnt,prim[400004];
long long pr[400004];
void getphi(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if( !vis[i] ){
            prim[++cnt] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= cnt; j++){
            if(i * prim[j] > n) break;
            vis[i * prim[j]] = true;
            if(i % prim[j] == 0){
                phi[i * prim[j]] = prim[j] * phi[i];break;
            }
            else{
                phi[i * prim[j]] = phi[i] * (prim[j] - 1);
            }
        }
    }
    for(int i = 1; i < n; i++){
        pr[i]=pr[i-1]+phi[i];
    }
}
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    getphi(40001);
    int T=read();
    for(;T--;){
        int n=read();
        cout<<2*pr[n-1]+1<<endl;
    }
    
}