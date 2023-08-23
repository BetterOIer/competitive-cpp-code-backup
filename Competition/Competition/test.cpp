#include<iostream>
#include<cmath>
using namespace std;
int pd(int n) {                  
    bool a[n+1]={0};
    int b[30], sum = 0;
    double t = sqrt(n);
    for (int i = 2;i<=t;++i){
        if (!a[i]){
            sum++;
            b[sum] = a[i];
            for(int w = 1; w<= sum;++w){
                a[i*b[w]]=1;
            }
        }
        else{
            a[i*2] = 1;
        }
    }
    if(!a[n]){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    if(pd(5)){
        cout<<"yes.";
    }
    return 0;
}