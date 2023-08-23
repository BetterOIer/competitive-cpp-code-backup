#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
ll sum;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        int v=read();
        sum+=v;
    }
    ld eve=(ld)sum/(n+1);
    for(int i=1;i<=n;i++){
        if(i==1)printf("%.8Lf ",2*eve);
        else printf("%.8Lf ",eve);
    }
}