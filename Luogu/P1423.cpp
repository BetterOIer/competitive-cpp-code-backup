#include<iostream>
#include<cmath>
using namespace std;
#define VF 2.0
int main(){
    float x, sum = 0;
    cin>>x;
    int n;
    for(n = 0;sum<x;n++){
        
        sum+=VF*pow(0.98,n);
    }
    cout<<n;
    return 0;
} 