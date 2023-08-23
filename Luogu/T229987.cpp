#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned long long m,n,a;
    cin>>m>>n;
    a = pow(m+1,n-1);
    cout<<1*a%998244353;
    return 0;
} 