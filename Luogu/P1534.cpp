#include<iostream>
using namespace std;
int main(){
    int n,deep=0,a,b,he=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>b;
        deep=deep+a+b-8;
        he+=deep;
    }
    cout<<he;;
}