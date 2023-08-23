#include<iostream>
using namespace std;
int a[15];
int main(){
    int n;
    while(cin>>n){
        a[(n/2)/10]++;
    }
    for(int i =0;i<=10;i++){
        cout<<a[i]<<" ";
    }
}