#include<iostream>
#include<cmath>
using namespace std;
int n;
double ans,ANS=40000;
struct zz{
    double x,y,dis[16]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    bool vis=false;
}a[16];
void dfs(int x,int po){
    if(x==n){
        ANS=min(ans,ANS);
        return ;
    }
    for(int i = 1;i<=n;i++){
        if(a[i].vis==false){
            a[i].vis=true;
            ans+=a[po].dis[i];
            if(ans<ANS) dfs(x+1,i);
            ans-=a[po].dis[i];
            a[i].vis=false;
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i = 0;i<=n;i++){
        for(int w = i;w<=n;w++){
            if(a[i].dis[w]==-1){
                double d=sqrt(pow((a[i].x-a[w].x),2)+pow((a[i].y-a[w].y),2));
                a[i].dis[w]=d,a[w].dis[i]=d;
            }
        }
    }
    dfs(0,0);
    printf("%.2f",ANS);
    return 0;
}