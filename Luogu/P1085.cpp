#include<iostream>
using namespace std;
int main(){
    int w = 0, b = 0;
    for(int i = 1; i<=7; ++i){
        int a1, a2;
        cin>>a1>>a2;
        int a = a1+a2;
        if (a>8&&a>b){
            b = a;
            w = i;
        }     
    }
    cout<<w;

    return 0;
}