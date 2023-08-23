#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double dist(double x1,double x2,double y1,double y2){
    return sqrt((abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2)));
}
int main(){
    double sum=0,x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    sum=sum+dist(x1,x2,y1,y2)+dist(x2,x3,y2,y3)+dist(x1,x3,y1,y3);
    printf("%.2f", sum);
    return 0;
}