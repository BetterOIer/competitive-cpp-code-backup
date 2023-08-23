#include<iostream>
using namespace std;
int main(){
    int a[13], l = 0, sumgmm=0;
    for(int i = 1;i<=12;++i){
        cin>>a[i];
    }
    for(int i = 1;i<=12;++i){
        if(300+l<a[i]){
            cout<<"-"<<i;
            return 0;
        }
        else{
            l=l+300-a[i];
            if(l/100>=1){
                sumgmm= sumgmm+100*(l/100); 
                l=l-100*(l/100);
            }
        }
    }
    l = l+sumgmm*1.2;
    cout<<l;

    return 0;
} 