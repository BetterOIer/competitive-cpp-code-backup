#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x;
}
struct node{
    int x,id;
    inline bool operator <(const node &w)const{
        if(x==w.x)return id<w.id;
        return x<w.x;
    }
}a[5000005];
int n,m,b[5000005];
ll las,ans[5000005];
inline int lb(int x){return (x&-x);}
inline void add(int x){
    while(x<=n+1){
        b[x]+=1;
        x+=lb(x);
    }
}
inline int query(int x){
    int res=0;
    while(x){
        res+=b[x];
        x-=lb(x);
    }
    return res;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i].x=read(),a[i].id=i+1;
    }
    sort(a+1,a+1+n);
    if(n&1){
        int mor=query(a[1].id);
            add(a[1].id);
            ans[a[1].id-1]=0ll-las+mor;
            las+=a[1].x;
        for(int i=2;i<=n;i+=2){
            mor=query(a[i].id);
            add(a[i].id);
            ans[a[i].id-1]=1ll*a[i].x*(i-1)-las+mor;
            las+=a[i].x;
            mor=query(a[i+1].id);
            add(a[i+1].id);
            ans[a[i+1].id-1]=1ll*a[i+1].x*i-las+mor;
            las+=a[i+1].x;
        }
    }
    else{
        int mor;
        for(int i=1;i<=n;i+=2){
            mor=query(a[i].id);
            add(a[i].id);
            ans[a[i].id-1]=1ll*a[i].x*(i-1)-las+mor;
            las+=a[i].x;
            mor=query(a[i+1].id);
            add(a[i+1].id);
            ans[a[i+1].id-1]=1ll*a[i+1].x*i-las+mor;
            las+=a[i+1].x;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",(ans[i]>1ll*m-2ll?-1:ans[i]));
    }
}