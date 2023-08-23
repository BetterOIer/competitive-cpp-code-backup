#include<iostream>
using namespace std;
int main(){
    int n , d=1;
    cin>>n;
    while(n > 1){
        ++d;
        n = n/2;
        
    }
    cout<<d;
    return 0;
} 