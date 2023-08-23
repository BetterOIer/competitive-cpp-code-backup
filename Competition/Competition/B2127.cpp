#include<iostream>
using namespace std;
int main(){
    int n,suma = 1;
    cin>>n;
    for(int a =2; a<=n; ++a){
        for(int i =2; i*i<a; i++){
            if(a%i==0){
                suma = suma+a/i+i;
            }
        }
        if (suma == a){
            cout<<a<<endl;
        }
        else{
            suma = 1;
        }
    }
    return 0;
} 