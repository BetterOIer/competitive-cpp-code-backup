/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* 我会等枯树生出芽 开出新的花
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
#include<algorithm>
#define PI 3.14159265358979323846
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct point{
    double x;
    double y;
}p[500005],s[500005];
int n,cnt,top;
point operator+(const point a,const point b){return (point){a.x+b.x,a.y+b.y};}
point operator-(const point a,const point b){return (point){a.x-b.x,a.y-b.y};}
double operator^(const point a,const point b){return a.x*b.x+a.y*b.y;}
double operator*(const point a,const point b){return a.x*b.y-a.y*b.x;}
double len(point a){return 1.0*sqrt(a.x*a.x+a.y*a.y);}
double cross(point a,point b,point c){return (a-b)*(c-b);}
bool cmp(point a,point b){return a.x!=b.x? a.x<b.x:a.y<b.y;}
double Andrew(){
    sort(p+1,p+cnt+1,cmp);
    for(int i = 1;i<=cnt;i++){
        while(top>1&&cross(s[top-1],p[i],s[top])<=0)top--;
        s[++top]=p[i];
    }
    int t=top;
    for(int i = cnt-1;i>=1;i--){
        while(top>t&&cross(s[top-1],p[i],s[top])<=0)top--;
        s[++top]=p[i];
    }
    double res=0;
    for(int i = 1;i<top;i++){
        res+=len(s[i]-s[i+1]);
    }
    return res;
}
int main(){
    n=read();
    double x,y,r;
    cin>>x>>y>>r;
    double thelt=atan((y/2-r)/(x/2-r));
    for(int i = 1;i<=n;i++){
        double xc,yc,rc,xie;
        cin>>yc>>xc>>rc;
        xie=sqrt(x*x+y*y)*0.5;
        xie-=sqrt(2)*r;

        p[++cnt].y=xie*cos(thelt+rc)+xc;
        p[cnt].x=xie*sin(thelt+rc)+yc;

        p[++cnt].y=xie*cos(PI-thelt+rc)+xc;
        p[cnt].x=xie*sin(PI-thelt+rc)+yc;

        p[++cnt].y=xie*cos(-thelt+rc)+xc;
        p[cnt].x=xie*sin(-thelt+rc)+yc;

        p[++cnt].y=xie*cos(PI+thelt+rc)+xc;
        p[cnt].x=xie*sin(PI+thelt+rc)+yc;
    }
    
    double l=Andrew();
    printf("%.2lf",l+2*PI*r);
    return 0;
}