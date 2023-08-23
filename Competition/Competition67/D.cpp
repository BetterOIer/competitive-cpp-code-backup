#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y;
}a[35];
long long n;
long long sx,sy;
long long ansx,ansy;
long long ans=1e9,t;
const long long delta=1;
inline long long cal(long long x,long long y) {
    long long rt=0;
    for (long long i=1;i<=n;i++) {
        long long cnt=0;
        long long deltax=x-a[i].x,deltay=y-a[i].y;
        if(deltax*deltay<=0){
            cnt+=abs(deltax)+abs(deltay);
        }else if(deltax*deltay>0){
            if(abs(deltax)<abs(deltay)){
                cnt+=abs(deltay);
            }else cnt+=abs(deltax);
        }
        rt=max(rt,cnt);
    }
    return rt;
}
inline void simulate_anneal() {
    long long x=ansx,y=ansy;
    t=30;
    while (t>1e-14) {
        long long X=x+((rand()<<1)-RAND_MAX)*t;
        long long Y=y+((rand()<<1)-RAND_MAX)*t;
        long long now=cal(X,Y);
        long long Delta=now-ans;
        if (Delta<0) {
            x=X,y=Y;
            ansx=x,ansy=y,ans=now;
        }
        //else if (exp(-1.0*Delta/t)*RAND_MAX>rand()) x=X,y=Y;
        t-=delta;
    }
}
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        string l;
        cin>>l;
        for(long long j=0;j<l.length();j++){
            if(l[j]=='N')a[i].x++;
            else a[i].y++;
        }
        sx+=a[i].x;
        sy+=a[i].y;
    }
    ansy=sy/n;
    ansx=sx/n;
    simulate_anneal();
    cout<<ans<<endl;
    for(long long i = 1;i<=ansx;i++){
        cout<<"N";
    }
    for(long long i = 1;i<=ansy;i++){
        cout<<"B";
    }
}