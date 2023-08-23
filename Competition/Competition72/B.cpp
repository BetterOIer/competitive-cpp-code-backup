/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
struct LINE{
    long long a;
    long long b;
    long long c;
};
LINE line[3005];
struct point{
    double x;
    double y;
};
map<pair<int,int>,point>m;
void get_po(int x,int y){
    long long 
    cnt1=1LL*line[x].a*line[y].c-1LL*line[x].c*line[y].a,
    cnt2=1LL*line[x].b*line[y].a-1LL*line[x].a*line[y].b,
    cnt3=1LL*line[y].c*line[x].b-1LL*line[y].b*line[x].c,
    cnt4=1LL*line[y].b*line[x].a-1LL*line[y].a*line[x].b;
    point now;
    now.y=1.0*cnt1/cnt2;
    now.x=1.0*cnt3/cnt4;
    m[make_pair(x,y)]=now;
}
point mid(point a,point b){
    return (point){0.5*(a.x+b.x),0.5*(a.y+b.y)};
}
point q_3(point a,point b){
    return (point){(2.0*a.x+1.0*b.x)/3,(2.0*a.y+1.0*b.y)/3};
}
double len(point a,point b){
    return __builtin_sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool vaild(int l1,int l2,int l3){
    point
    p0=(point){0,0},
    p1=m[make_pair(l1,l2)],
    p2=m[make_pair(l1,l3)],
    p3=m[make_pair(l2,l3)],
    m1 = mid(p1,p2),
    q_33 = q_3(m1,p3);
    double
    len1=len(q_33,p0),
    len2=len(q_33,p3);
    if(abs(len1-len2)<1e-8)return true;
    else return false;
}
int main(){
    freopen("geometry.in","r",stdin);
    freopen("geometry.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        line[i].a=read(),line[i].b=read(),line[i].c=read();
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            get_po(i,j);
        }
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            for(int w = j+1;w<=n;w++){
                if(vaild(i,j,w)){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}