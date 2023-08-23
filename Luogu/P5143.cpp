#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct dirc{
    int x,y,z;
}a[50001];
int comp(dirc a,dirc b){
    return a.z<b.z;
}
int main(){
    int n;
    cin>>n;
    double dis = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+n+1,comp);
    for(int i = 1;i<=n-1;i++){
        dis+=sqrt(pow(a[i].x-a[i+1].x,2)+pow(a[i].y-a[i+1].y,2)+pow(a[i].z-a[i+1].z,2));
    }
    printf("%.3f",dis);
    return 0;
} 