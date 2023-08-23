#include<iostream>
using namespace std;
int main(){
    int n, l,i, sum;
    cin>>n;
    l = n;
    for(sum = 1; l!=1;++sum){
        if(l%2==0){
            l = l/2;
        }
        else{
            l= l*3+1;
        }
    }
    int a[sum+1];
    a[1]=n;
    for(i = 2; n!=1;++i){
        if(n%2==0){
            n = n/2;
            a[i]=n;
        }
        else{
            n= n*3+1;
            a[i]=n;
        }
    }
    for (--i;i>0;--i){
        cout<<a[i]<<" ";
    }
    return 0;
} 