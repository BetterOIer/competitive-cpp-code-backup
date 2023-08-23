#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
#include<cmath>
using namespace std;
//int a[];
struct soilder{
    int x,y;
}a[10005];
bool comp1(soilder a,soilder b){
    return a.y<b.y;
}
bool comp2(soilder a,soilder b){
    return a.x<b.x;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,comp1);
    int avey,avex;
    //if((a[1].y+a[n].y)%2==0){
        avey = (a[1].y+a[n].y)/2;
    //}else{

    //}

    for(int i = 1;i<=n;i++){
        ans+=abs(a[i].y-avey);
    }
    sort(a+1,a+n+1,comp2);
    avex = a[n/2].x;
    for(int i = 1;i<=n;i++){
        ;
    }
 	//fclose(stdin);
    //fclose(stdout);
    cout<<ans;
    return 0;
} 