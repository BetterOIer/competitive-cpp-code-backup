#include<iostream>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
long long gcd(long long a,long long b){
    return (a%b==0)?b:gcd(b,a%b);
}
void exgcd(long long a,long long b,long long &x,long long &y){
    if(!b){
        x=1,y=0;
        return;
    }
    long long p;
    exgcd(b,a%b,x,y);
    p=x;
    x=y;
    y=p-(a/b)*y;
    return;
}
int main(){
    int T=read();
    for(;T--;){
        long long a=read(),b=read(),c=read(),g,x=0,y=0,num=0,minx,maxx,maxy,miny;
        g=gcd(a,b);
        if(c%g!=0){cout<<-1<<endl;continue;}
        a/=g,b/=g,c/=g;
        exgcd(a,b,x,y);
        x*=c,y*=c;
        minx=x>0&&x%b!=0? x%b:x%b+b;
        maxy=(c-minx*a)/b;
        miny=y>0&&y%a!=0? y%a:y%a+a;
        maxx=(c-miny*b)/a;
        if(maxx>0) num=(maxx-minx)/b+1;
        if(num)cout<<num<<" "<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
        else cout<<minx<<" "<<miny<<endl;
        
    }
}