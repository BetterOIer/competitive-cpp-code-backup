#include<iostream>
#include<cmath>
using namespace std;
float a=1.9,b;
int main(){
    int n,m;
    cin>>n>>m;
    b=n+0.1*m;
    b=floor(b/a);
    cout<<b;
}