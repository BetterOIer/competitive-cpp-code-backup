#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    double f = (pow((1+pow(5,0.5))/2.0,n)-pow((1-pow(5,0.5))/2.0,n))/pow(5,0.5);
    printf("%.2f",f);
    return 0;
} 