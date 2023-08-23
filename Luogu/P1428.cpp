#include<iostream>
using namespace std;
int main(){
    int n, sum = 0;
    cin>>n;
    int a[n+1];
    for(int i = 1;i<=n; ++i){
        cin>>a[i];
    }
    for(int i = 1;i<=n; ++i){
        for(int w = 1;w<i; ++w){
            if(a[w]<a[i]){
                sum++;
            }    
        }
        cout<<sum<<" ";
        sum = 0;
    }
    return 0;
} 