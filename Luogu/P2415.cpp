#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n, sum=0,ans=-1,am;
    while(cin>>n){
        sum+=n;
        ans++;
    }
    am = sum*pow(2,ans);
    cout<<am;
    return 0;
} 