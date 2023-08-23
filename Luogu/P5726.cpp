#include<iostream>
using namespace std;
int main(){
    int n, maxi=0, mini=1000, sum =0;
    float average;
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
        sum+=a;
    }
    sum=sum-maxi-mini;
    average = sum*1.0/(n-2);
    printf("%.2f", average);
    return 0;
} 