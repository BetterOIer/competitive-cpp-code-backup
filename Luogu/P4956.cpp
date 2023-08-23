#include<iostream>
using namespace std;
int main(){
    int n, k, x;
    cin>>n;
    for(x = 100;x>=0;x--){
        k = (n/364-x)/3;
        if(n==364*(x+3*k)&&k>0){
            cout<<x<<endl<<k;
            break;
        }
    }
    return 0;
} 