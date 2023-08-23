#include<iostream>
using namespace std;
int main(){
    int n, l, sum = 2, fenzi, fenmu;
    cin>>n;
    l = n;
    for(int i = 1;l>i;++i){
        l -= i;
        sum+=1;
    }
    if(sum%2==1){
        fenzi = l;
        fenmu = sum-l;
    }
    else{
        fenzi = sum-l;
        fenmu = l;
    }
    cout<<fenzi<<"/"<<fenmu;
    return 0;
} 