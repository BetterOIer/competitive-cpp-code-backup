#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int sj[100001];
struct sl{
    int x;
    int y;
    int shili;
}a[100001];
bool comp(sl a,sl b){
    return a.shili<b.shili;
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].shili;
    }
    sort(a+1,a+n+1,comp);
    a[1].x=1;
    a[1].y=1;
    int f_y,l_y;
    bool full = true;
    f_y = a[1].y;
    l_y = a[1].y;
    for(int i = 2;i<=n;i++){
        if(a[i].shili==a[i-1].shili){
            a[i].x = a[i-1].x;
            if(!full){
                a[i].y=a[i-1].y-1;
                if(a[i].y==f_y){
                    full = true;
                }
            }else if(full){
                a[i].y = l_y+1;
                l_y++;
            }
        }else if(a[i].shili==a[i-1].shili+1){
            if(full&&(f_y!=l_y)){
                full = false;
            }else{
                f_y = a[i-1].y;
            }
            a[i].y = l_y;
            a[i].x = a[i-1].x+1;
        }else if(a[i].shili>a[i-1].shili+1){
            a[i].x = a[i-1].x+1;
            a[i].y = l_y+1;
            f_y = a[i].y;
            l_y = a[i].y;
            full = true;
        }
    }
    int ymax=0;
    /* for(int i = 1;i<=n;i++){
        cout<<a[i].shili<<" "<<a[i].x<<" "<<a[i].y<<endl;
    } */
    for(int i = 1;i<=n;i++){
        sj[a[i].y]++;
        ymax = max(ymax,a[i].y);
    }
    int ans = INT32_MAX;
    for(int i = 1;i<=ymax;i++){
        ans = min(ans,sj[i]);
    }
     cout<<ans;
    return 0;
}