#include<iostream>
using namespace std;
int hzct(int n){
    if(n==1){
        return 1;
    }
    return (hzct(n-1)+1)*2;
}
int main(){
    int n;
    cin>>n;
    cout<<hzct(n);
    return 0;
}