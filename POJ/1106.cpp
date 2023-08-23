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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct point{
    int x;
    int y;
}p[100006];
point operator+(const point a,const point b){
    return (point){a.x+b.x,a.y+b.y};
}
point operator-(const point a,const point b){
    return (point){a.x-b.x,a.y-b.y};
}
int operator^(const point a,const point b){
    return a.x*b.x+a.y*b.y;
}
int operator*(const point a,const point b){
    return a.x*b.y-a.y*b.x;
}
double len(point a){
    return 1.0*sqrt(a.x*a.x+a.y*a.y);
}
int cross(point a,point b,point c){
    return (a-b)*(c-b);
}
int main(){
    while(true){
        int X=read(),Y=read();
        double R;
        cin>>R;
        point M=(point){X,Y};
        if(R<0)break;
        int n=read(),tot=0;
        for(int i = 1;i<=n;i++){
            point now;
            now.x=read(),now.y=read();
            if(len(now-M)>R) continue;
            p[++tot]=now;
        }
        int ans=0;
        for(int i = 1;i<=tot;i++){
            int cnt=0;
            for(int j=1;j<=tot;j++){
                if(cross(p[i],M,p[j])>=0)cnt++;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}