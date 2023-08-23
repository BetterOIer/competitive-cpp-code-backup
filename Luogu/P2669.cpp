#include<iostream>
using namespace std;
int main(){
    int k, n = 0, sum=0;
    cin>>k;
    for(n =1;k>=n;++n){
        k = k-n;
        sum+=n*n;
    }
    if(k!=0){
        sum+=k*n;
    }
    cout<<sum;
    return 0;
} 