#include<iostream>
#include<cmath>
using namespace std;
long long xmin,ymin,zmin,xmax,ymax,zmax,x,y,z;
int main(){
    int a;
    xmin = ymin = zmin = 9223372036854775807;
    cin>>a;
    for(int i = 1;i<=a;i++){
        cin>>x>>y>>z;
        xmin = x<xmin? x:xmin;
        xmax = x>xmax? x:xmax;
        ymin = y<ymin? y:ymin;
        ymax = y>ymax? y:ymax;
        zmin = z<zmin? z:zmin;
        zmax = z>zmax? z:zmax;
    }
    if((xmax-xmin+1)*(ymax-ymin+1)*(zmax-zmin+1)==a){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
} 