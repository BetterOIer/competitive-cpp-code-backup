/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
struct district{
    int y;
    int x;
}po[205];
int dpx[205][80005],dpy[205][80005];
int minn=2147483647,n;
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        po[i].y=read(),po[i].x=read();
    }
    int ansx=0,ansy=0;
    for(int i = 1;i<=n;i++){
        ansx-=po[i].x*po[i].x;
        ansy-=po[i].y*po[i].y;
    }
    dpx[0][40000]=dpy[0][40000]=1;
    for(int i = 1;i<=n;i++){
        for(int j = po[i].x;j<=80000-po[i].x;j++){
            if(dpx[i-1][j])dpx[i][j-po[i].x]=dpx[i][j+po[i].x]=1;
        }
    }
    for(int i = 0;i<=40000;i++){
        if(dpx[n][40000+i]||dpx[n][40000-i]){
            ansx+=i*i;
            break;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = po[i].y;j<=80000-po[i].y;j++){
            if(dpy[i-1][j])dpy[i][j-po[i].y]=dpy[i][j+po[i].y]=1;
        }
    }
    for(int i = 0;i<=40000;i++){
        if(dpy[n][40000+i]||dpy[n][40000-i]){
            ansy+=i*i;
            break;
        }
    }
    float ans=0.5*(ansy+ansx);
    printf("%.2f",ans);
    return 0;
}