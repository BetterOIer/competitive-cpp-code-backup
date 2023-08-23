#include<iostream>
using namespace std;
unsigned long long a[19];
int main(){
    int n;
    cin>>n;
    a[0]=1;
    a[1]=1;
    for(int i = 2;i<=n;i++){
        for(int w = 0,j=i-1;w<=i-1;w++,j--){
            a[i]+=a[w]*a[j];
        }
    }
    cout<<a[n];
    return 0;
} 