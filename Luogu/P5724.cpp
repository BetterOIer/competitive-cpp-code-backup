#include<iostream>
using namespace std;
int main(){
    int n, maxi=0, mini=1000;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a;
        cin>>a;
        if(a>maxi){
            maxi = a;
        }
        if(a<mini){
            mini = a;
        }
    }
    cout<<maxi-mini;
    return 0;
} 