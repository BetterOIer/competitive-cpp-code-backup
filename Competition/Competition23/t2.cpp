#include<iostream>
using namespace std;
inline long long read1(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
inline int read2(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int a[100005],b[100005];
long long gcd(int m,int n){
    while (n != 0){
        long long t = m%n;
        m = n;
        n = t;
    }
    return m;
}
int main(){
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);
    long long n,m,k,c=0;
    n=read1(),m=read1(),k=read1();
    long long GCD=gcd(n,m),LCM;
    LCM=n*m/GCD;
    long long pro=k/LCM,left=k%LCM,g,gg;
    for(int i = 1;i<=n;i++) a[i]=read2();
    for(int i = 1;i<=m;i++) b[i]=read2();
    if(pro==0){
        for(long long i = 1;i<=left;i++){
            if(a[(i-1)%n+1]<b[(i-1)%m+1])++c;
        }
        printf("%lld",c);
        return 0;
    }
    else if(pro>0){
        for(long long i = 1;i<=LCM;i++){
            if(a[(i-1)%n+1]<b[(i-1)%m+1])++c;
            if(i==left)g=c;
        }
        gg=c;
        printf("%lld",pro*gg+g);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
}