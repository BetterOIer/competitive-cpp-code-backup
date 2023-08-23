/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct point{
    long long x;
    long long y;
}a[5006],b[5006];
int n,m,ans[5006];
point operator+(const point a,const point b){return (point){a.x+b.x,a.y+b.y};}
point operator-(const point a,const point b){return (point){a.x-b.x,a.y-b.y};}
long long operator^(const point a,const point b){return a.x*b.x+a.y*b.y;}
long long operator*(const point a,const point b){return a.x*b.y-a.y*b.x;}
double len(point a){return 1.0*sqrt(a.x*a.x+a.y*a.y);}
long long cross(point a,point b,point c){return (a-b)*(c-b);}

long long find(point p){
    long long l=-1,r=n+1;
    while(l+1<r){
        long long mid=((l+r)>>1);
        if(cross(b[mid],p,a[mid])<=0)l=mid;
        else r=mid;
    }
    return l;
}

int main(){
    while(scanf("%d",&n),n){
        long long x1,y1,y2;
        m=read(),x1=read(),y1=read(),y2=read(),y2=read();
        a[0].x=x1,a[0].y=y1,b[0].x=x1,b[0].y=y2;
        for(long long i = 1,u,l;i<=n;i++){
            u=read(),l=read();
            a[i].x=u,a[i].y=y1;b[i].x=l,b[i].y=y2;
        }
        for(long long i = 0;i<=5005;i++)ans[i]=0;
        point p;
        while(m--){
            p.x=read(),p.y=read();
            ans[find(p)]++;
        }
        for(int i = 0;i<=n;i++)cout<<i<<": "<<ans[i]<<endl;
        puts("");
    }
    return 0;
}