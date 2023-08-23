#include<iostream>
using namespace std;
const int maxn=1000005;
int a[maxn],c[maxn],d[maxn],n,q,opt,l,r,x;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);return x*f;}
inline int lowbit(int x){return x&(-x);}
inline int getSum(int x){int ans = 0;for(;x;x -= lowbit(x))ans += c[x];return ans;}
inline bool re(int x){return x>0;}
inline void update(int x, int value){for(;x <= n;x += lowbit(x)) c[x] += value;}
signed main(){
    n=read(),q=read();
    for(int i = 1; i <= n;i++){
        a[i]=read();
        d[i]=a[i]-a[i-1];
        update(i, re(d[i]));
    }
    for(;q--;){
        opt=read(),l=read(),r=read();
        if(opt==1){
            x=read();
            update(l,re(d[l]+x)-re(d[l]));
            d[l]+=x;
            update(l,re(d[r+1]-x)-re(d[r+1]));
            d[r+1]-=x;
        }else puts((getSum(r)-getSum(l))==r-l? "Yes":"No");
    }
    return 0;
} 