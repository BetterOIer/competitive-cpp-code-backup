#include<iostream>
#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
#include<cmath>
using namespace std;
int sj[15];
struct sl{
    int x;
    int y;
    bool f = false;
    long long shili;
}a[15];
bool comp(sl a,sl b){
    return a.shili<b.shili;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].shili;
    }
    sort(a+1,a+n+1,comp);
    a[1].x=1;
    a[1].y=1;
    a[1].f=true;
    int /*f_x,*/f_y,l_x,l_y;
    //f_x = a[1].x;
    f_y = a[1].y;
    l_y = a[1].y;
    l_x = a[1].x;
    for(int i = 2;i<=n;i++){
        if(a[i].shili==a[i-1].shili){
            if(a[i-1].y-2>f_y){
                a[i].y = a[i-1].y-1;
                a[i].x = a[i-1].x;
            }else if(a[i-1].y-2<=f_y){
                a[i].y=l_y+1;
                a[i].x=l_x;
                l_y = a[i].y;
            }
        }else if(a[i].shili==a[i-1].shili+1){
            a[i].y = l_y;
            a[i].x = l_x+1;
            a[i].f = true;
            l_x = a[i].x;
            f_y = a[i].y;
        }else if(a[i].shili>a[i-1].shili+1){
            a[i].y = l_y+1;
            a[i].x = l_x+1;
            a[i].f = true;
            l_x = a[i].x;
            l_y = a[i].y;
            f_y = a[i].y;
        }
    }
    int ymax=0;
    for(int i = 1;i<=n;i++){
        sj[a[i].y]++;
        ymax = max(ymax,a[i].y);
    }
    int ans = INT32_MAX;
    for(int i = 1;i<=ymax;i++){
        ans = min(ans,sj[i]);
    }
     cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 