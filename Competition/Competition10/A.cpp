#include<iostream>
#include<windows.h>
using namespace std;
int main(){
    int n,a,x=0,y=100000000;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a;
        x=max(x,a);
        y=min(y,a);
    }
    unsigned long long ans=(x-y)*(n-1);
    cout<<ans;
}