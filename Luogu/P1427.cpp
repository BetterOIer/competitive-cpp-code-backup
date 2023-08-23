#include<iostream>
using namespace std;
int main(){
    int a[101]={1}, i;
    for(i=1;a[i-1]!=0;++i){
        cin>>a[i];
        a[i+1]=1;
    }
    for(i=i-1;i>1;--i){
        cout<<a[i-1]<<" ";
    }

    return 0;
} 